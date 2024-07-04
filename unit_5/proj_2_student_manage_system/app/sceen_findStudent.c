//
// Created by asus on 2024-07-02.
//
#include <stdlib.h>
#include "navigator.h"
#include "input_output.h"
#include "../shared/delay_ms.h"
#include "../data/linked_list.h"

SCREEN_DEFINE(SCREEN_FindStudent) {
    int choice = 0;
    Student studentPtr;
    LINKED_Status status;

    printStringLn("Please Choose what field you want to search with:", TextStyle_label);

    printInt(1, TextStyle_number);
    printStringLn(" -> By first name", TextStyle_body);

    printInt(2, TextStyle_number);
    printStringLn(" -> By roll ID", TextStyle_body);

    printInt(0, TextStyle_number);
    printStringLn(" -> to return screen", TextStyle_body);

    printString("\n---> Enter your choice: ", TextStyle_question);

    choice = readInt();

    switch (choice) {
        case 1: {
            char nameField[50];

            printString("\n---> Enter First name: ", TextStyle_question);
            readString(nameField);

            status = LINKED_findByFirstName(nameField, &studentPtr);

            break;
        }
        case 2: {
            int id = 0;
            printString("\n---> Enter roll ID: ", TextStyle_question);
            id = readInt();

            status = LINKED_findById(id, &studentPtr);

            break;
        }
        case 0: {
            navigatorPop();
            return;
            break;
        }
        default: {
            navigatorPushReplacement(SCREEN_FindStudent);
            return;
        }
    }

    switch (status) {
        case STATUS_done: {
            printStringLn("\nThe student is found in DATABASE", TextStyle_body);

            printString("first Name: ", TextStyle_label);
            printString(studentPtr.firstName, TextStyle_body);
            printString("\n", TextStyle_body);

            printString("last Name: ", TextStyle_label);
            printString(studentPtr.lastName, TextStyle_body);
            printString("\n", TextStyle_body);

            printString("Roll ID: ", TextStyle_label);
            printInt(studentPtr.rollId, TextStyle_number);
            printString("\n", TextStyle_body);

            printString("GPA: ", TextStyle_label);
            printFloat(studentPtr.gpa, TextStyle_number);
            printString("\n", TextStyle_body);

            printString("Courses ID: ", TextStyle_label);

            int j;
            for (j = 0; j < 5; ++j) {
                printInt(studentPtr.coursesId[j], TextStyle_number);
                printString(" ", TextStyle_label);
            }
            printString("\n\n", TextStyle_body);


            break;
        }
        default: {
            printStringLn("Failed to get the desired student", TextStyle_error);
            delay_ms(2000);
            navigatorPushReplacement(SCREEN_FindStudent);
            return;
            break;
        }
    }

    printStringLn("Whats next:", TextStyle_label);

    printInt(1, TextStyle_number);
    printStringLn(" -> Reload the current screen", TextStyle_body);

    printInt(0, TextStyle_number);
    printStringLn(" -> Return to menu screen", TextStyle_body);

    printString("\n---> Enter your choice: ", TextStyle_question);

    choice = readInt();

    if (choice == 0) {
        navigatorPop();
    } else {
        navigatorPushReplacement(SCREEN_FindStudent);
    }
}

