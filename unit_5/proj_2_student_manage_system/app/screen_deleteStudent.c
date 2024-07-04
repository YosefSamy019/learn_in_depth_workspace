//
// Created by asus on 2024-07-02.
//
#include "navigator.h"
#include "input_output.h"
#include "../shared/delay_ms.h"
#include "../shared/models.h"
#include "../shared/debug.h"
#include "../data/linked_list.h"

SCREEN_DEFINE(SCREEN_deleteStudent) {
    int rollID, choice;
    Student student;
    LINKED_Status status;

    printStringLn("Enter roll ID to delete student, ", TextStyle_label);
    printString("Enter or -1 to return screen:  ", TextStyle_label);
    rollID = readInt();

    if(rollID == -1) {
        navigatorPop();
        return;
    }
    status = LINKED_findById(rollID, &student);
    if (status == STATUS_done) {
        printString("Do you want to delete \"", TextStyle_question);
        printString(student.firstName, TextStyle_question);
        printString(" ", TextStyle_body);
        printString(student.lastName, TextStyle_question);
        printStringLn("\", Are you sure?", TextStyle_question);

        printString("Enter 1 to delete:  ", TextStyle_question);
        choice = readInt();

        if (choice == 1) {
            if (LINKED_deleteById(rollID) == STATUS_done) {
                printStringLn("Student Removed Successfully", TextStyle_body);
            } else {
                printStringLn("Failed to remove Student", TextStyle_error);
            }
            delay_ms(2000);
            navigatorPushReplacement(SCREEN_deleteStudent);
        } else {
            navigatorPushReplacement(SCREEN_deleteStudent);
        }

    } else if (status == STATUS_item_not_found) {
        printStringLn("Failed, Thd ID is not found", TextStyle_error);
        delay_ms(2000);
        navigatorPushReplacement(SCREEN_deleteStudent);
    } else {
        PRINT_DEBUG("UNHANDLED CASE", 0);
        delay_ms(2000);
        navigatorPop();
    }
}
