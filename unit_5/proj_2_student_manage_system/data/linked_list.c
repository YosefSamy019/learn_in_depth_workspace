//
// Created by asus on 2024-07-02.
//

#include "linked_list.h"
#include "stdlib.h"
#include "string.h"

#include "../shared/debug.h"
#include "../file_io/file_io.h"

#define NULL ((void*)0)

static struct SNode *startNode = NULL;


static void copyStudent(Student *to, Student *from) {
    if (to == NULL) return;

    strcpy(to->firstName, from->firstName);
    strcpy(to->lastName, from->lastName);
    to->rollId = from->rollId;
    to->gpa = from->gpa;
    strcpy(to->coursesId, from->coursesId);
}

enum LINKED_Status LINKED_addStudentManual(Student student) {

    struct SNode *newItemPtr = malloc(sizeof(struct SNode));
    struct SNode *tempPtr;

    if (newItemPtr == NULL) {
        return STATUS_failed_to_alloc;
    }

    //check is repeated id
    if (LINKED_findById(student.rollId, NULL) == STATUS_item_not_found) {
        copyStudent(&(newItemPtr->data), &student);
        newItemPtr->next = NULL;

        if (startNode == NULL) {
            startNode = newItemPtr;
            return STATUS_done;
        } else {
            tempPtr = startNode;
            while (tempPtr->next != NULL) {
                tempPtr = tempPtr->next;
            }
            tempPtr->next = newItemPtr;
            return STATUS_done;
        }
    } else {
        return STATUS_failed_repeated_id;
    }
}


void LINKED_debugPrint() {
    if (ENABLE_DEBUG == 0) return;

    if (startNode == NULL) {
        printf("[LINKED DEBUG] empty list\n");
    } else {
        struct SNode *tempPtr = startNode;
        while (tempPtr != NULL) {
            Student s = tempPtr->data;
            printf("[LINKED DEBUG] [%s %s] \t[%d] \t[%f] \t[%d %d %d %d %d]\n", s.firstName, s.lastName, s.rollId,
                   s.gpa, s.coursesId[0], s.coursesId[1], s.coursesId[2], s.coursesId[3], s.coursesId[4]);

            tempPtr = tempPtr->next;
        }
    }
}

enum LINKED_Status LINKED_findById(unsigned int rollId, Student *ptrStudent) {
    struct SNode *tempPtr = startNode;

    while (tempPtr != NULL) {
        if (tempPtr->data.rollId == rollId) {
            copyStudent(ptrStudent, &(tempPtr->data));
            return STATUS_done;
        }
        tempPtr = tempPtr->next;
    }
    return STATUS_item_not_found;
}

enum LINKED_Status LINKED_findByFirstName(char name[50], Student *ptrStudent) {
    struct SNode *tempPtr = startNode;
    char operator1[50], operator2[50];

    while (tempPtr != NULL) {
        strcpy(operator1, strlwr(name));
        strcpy(operator2, strlwr(tempPtr->data.firstName));

        if (strcmp(operator1, operator2) == 0) {
            copyStudent(ptrStudent, &(tempPtr->data));
            return STATUS_done;
        }
        tempPtr = tempPtr->next;
    }
    return STATUS_item_not_found;
}

unsigned int LINKED_getCount() {
    struct SNode *tempPtr = startNode;
    unsigned int length = 0;

    while (tempPtr != NULL) {
        length++;
        tempPtr = tempPtr->next;
    }

    return length;
}

unsigned int LINKED_getStudentsInCourse(unsigned char courseId, Student *buffer) {
    struct SNode *tempPtr = startNode;
    unsigned int length = 0, i;

    while (tempPtr != NULL) {
        for (i = 0; i < 5; ++i) {
            if (tempPtr->data.coursesId[i] == courseId) {
                copyStudent(buffer + length, &(tempPtr->data));
                length++;
                break;
            }
        }
        tempPtr = tempPtr->next;
    }

    return length;
}

enum LINKED_Status LINKED_deleteById(unsigned int rollId) {
    struct SNode *curPtr = startNode, *prePtr = NULL;

    if (curPtr == NULL) {
        return STATUS_item_not_found;
    } else if (startNode->data.rollId == rollId) {
        startNode = curPtr->next;
        free(curPtr);
        return STATUS_done;
    } else {
        while (curPtr != NULL) {
            if (curPtr->data.rollId == rollId) {
                prePtr->next = curPtr->next;
                free(curPtr);

                return STATUS_done;
            }
            prePtr = curPtr;
            curPtr = curPtr->next;
        }
    }

    return STATUS_item_not_found;
}

enum LINKED_Status LINKED_updateStudent(unsigned int oldRollId, char *newFirstName, char *newLastName,
                                        int newRolId, float newGpa, char newCoursesID[5]) {

    struct SNode *tempPtr = startNode;
    int i;

    while (tempPtr != NULL) {
        if (tempPtr->data.rollId == oldRollId) {

            if (newFirstName != NULL) strcpy(tempPtr->data.firstName, newFirstName);
            if (newLastName != NULL) strcpy(tempPtr->data.lastName, newLastName);
            if (newRolId >= 0) tempPtr->data.rollId = newRolId;
            if (newGpa >= 0) tempPtr->data.gpa = newGpa;

            for (i = 0; i < 5; ++i) {
                if (newCoursesID[i] >= 0) tempPtr->data.coursesId[i] = newCoursesID[i];
            }

            return STATUS_done;
        }
        tempPtr = tempPtr->next;
    }
    return STATUS_item_not_found;
}


unsigned int LINKED_getAllStudents(Student *buffer) {
    struct SNode *tempPtr = startNode;
    unsigned int length = 0;

    while (tempPtr != NULL) {
        copyStudent(buffer + length, &(tempPtr->data));
        tempPtr = tempPtr->next;
        length++;
    }

    return length;
}

//------------------------

static Student _tempStudent;

void (*_successCallBack)(Student *student);

void (*_failCallBack)(Student *student);

static void readFromFileCallback(Student *student) {
    LINKED_Status status;

    copyStudent(&_tempStudent, student);
    status = LINKED_addStudentManual(_tempStudent);

    if (status == STATUS_done) {
        _successCallBack(&_tempStudent);
    } else {
        _failCallBack(&_tempStudent);
    }
}

void LINKED_addStudentFile(void (*successCallBack)(Student *student), void (*failCallBack)(Student *student)) {
    _successCallBack = successCallBack;
    _failCallBack = failCallBack;

    FILE_read(readFromFileCallback);
}