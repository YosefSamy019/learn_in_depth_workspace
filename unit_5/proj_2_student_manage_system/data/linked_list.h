//
// Created by asus on 2024-07-02.
//

#ifndef MAIN_C_LINKED_LIST_H
#define MAIN_C_LINKED_LIST_H

#include "../shared/models.h"

struct SNode {
    Student data;
    struct SNode *next;
};

typedef enum LINKED_Status {
    STATUS_failed_to_alloc,
    STATUS_failed_repeated_id,
    STATUS_item_not_found,
    STATUS_done
} LINKED_Status;


enum LINKED_Status LINKED_addStudentManual(Student student);


void LINKED_debugPrint();

enum LINKED_Status LINKED_findById(unsigned int rollId, Student *ptrStudent);

enum LINKED_Status LINKED_findByFirstName(char name[50], Student *ptrStudent);

unsigned int LINKED_getCount();

unsigned int LINKED_getStudentsInCourse(unsigned char courseId, Student *buffer);

enum LINKED_Status LINKED_deleteById(unsigned int rollId);

enum LINKED_Status LINKED_updateStudent(unsigned int oldRollId, char *newFirstName, char *newLastName,
                                        int newRolId, float newGpa, char newCoursesID[5]);

unsigned int LINKED_getAllStudents(Student *buffer);

void LINKED_addStudentFile(void (*successCallBack)(Student *student), void (*failCallBack)(Student *student));

#endif //MAIN_C_LINKED_LIST_H
