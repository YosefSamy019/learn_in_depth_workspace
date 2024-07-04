//
// Created by asus on 2024-07-02.
//

#include "navigator.h"
#include "input_output.h"
#include "../shared/delay_ms.h"
#include "../shared/models.h"
#include "../shared/debug.h"
#include "../data/linked_list.h"


static void successCallBackFile(Student *student);

static void failCallBackFile(Student *student);

SCREEN_DEFINE(SCREEN_addStudent) {
    int choice = 0;
    int temp;
    Student newStudent;
    LINKED_Status status;

    printStringLn("Please Choose how to add student:", TextStyle_label);

    printInt(1, TextStyle_number);
    printStringLn(" -> To Add Student Manually", TextStyle_body);

    printInt(2, TextStyle_number);
    printStringLn(" -> To Read from file", TextStyle_body);

    printInt(0, TextStyle_number);
    printStringLn(" -> To return to previous screen", TextStyle_body);

    printString("\n---> Enter your choice: ", TextStyle_question);

    choice = readInt();

    if (choice == 0) {
        navigatorPop();

    } else if (choice == 1) {
        printStringLn("Manually", TextStyle_label);

        printString("\n---> Enter first name: ", TextStyle_question);
        readString(newStudent.firstName);

        printString("\n---> Enter last name: ", TextStyle_question);
        readString(newStudent.lastName);

        printString("\n---> Enter roll id: ", TextStyle_question);
        newStudent.rollId = readInt();

        printString("\n---> Enter GPA: ", TextStyle_question);
        newStudent.gpa = readFloat();

        for (temp = 0; temp < 5; ++temp) {
            printString("\n---> Enter Course ID [ ", TextStyle_question);
            printInt(temp + 1, TextStyle_number);
            printString(" ] :", TextStyle_question);
            newStudent.coursesId[temp] = readInt();
        }

        //todo validate input

        printString("\n", TextStyle_body);
        status = LINKED_addStudentManual(newStudent);
        if (status == STATUS_failed_to_alloc) {
            printStringLn("Failed to allocate memory", TextStyle_error);
        } else if (status == STATUS_failed_repeated_id) {
            printStringLn("Failed, The roll id is repeated", TextStyle_error);
        } else if (status == STATUS_done) {
            printStringLn("Student Added Successfully", TextStyle_body);
        } else {
            PRINT_DEBUG("Unhandled Case", 0);
        }

    } else if (choice == 2) {
        printStringLn("Manually", TextStyle_label);

        LINKED_addStudentFile(successCallBackFile, failCallBackFile);

        printStringLn("\nWhats next:", TextStyle_label);

        printInt(1, TextStyle_number);
        printStringLn(" -> Reload the current screen", TextStyle_body);

        printInt(0, TextStyle_number);
        printStringLn(" -> Return to menu screen", TextStyle_body);

        printString("\n---> Enter your choice: ", TextStyle_question);

        choice = readInt();

        if (choice == 0) {
            navigatorPop();
        } else {
            navigatorPushReplacement(SCREEN_addStudent);
        }
        return;

    } else {
        printStringLn("Unknown Choice", TextStyle_error);
        delay_ms(2000);
        navigatorPushReplacement(SCREEN_addStudent);
    }

    delay_ms(2000);
    navigatorPushReplacement(SCREEN_addStudent);
}

static void successCallBackFile(Student *student) {
    printString("Add Student: ", TextStyle_label);
    printString(student->firstName, TextStyle_body);
    printString(" ", TextStyle_body);
    printStringLn(student->lastName, TextStyle_body);

    printString("Roll ID: ", TextStyle_label);
    printIntLn(student->rollId, TextStyle_number);

    printString("Status: ", TextStyle_label);
    printStringLn("Success \n", TextStyle_question);

}

static void failCallBackFile(Student *student) {
    printString("Add Student: ", TextStyle_label);
    printString(student->firstName, TextStyle_body);
    printString(" ", TextStyle_body);
    printStringLn(student->lastName, TextStyle_body);

    printString("Roll ID: ", TextStyle_label);
    printIntLn(student->rollId, TextStyle_number);

    printString("Status: ", TextStyle_label);
    printStringLn("Fail \n", TextStyle_error);
}