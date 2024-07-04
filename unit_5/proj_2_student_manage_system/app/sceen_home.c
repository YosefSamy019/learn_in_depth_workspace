//
// Created by asus on 2024-07-02.
//

#include <stdlib.h>
#include "navigator.h"
#include "input_output.h"
#include "../shared/delay_ms.h"

SCREEN_DEFINE(SCREEN_home) {
    int choice = 0;

    printStringLn("Please Choose what you want to perform:", TextStyle_label);

    printInt(1, TextStyle_number);
    printStringLn(" -> To Add Student", TextStyle_body);

    printInt(2, TextStyle_number);
    printStringLn(" -> To Search about student", TextStyle_body);

    printInt(3, TextStyle_number);
    printStringLn(" -> To find students registered in course", TextStyle_body);

    printInt(4, TextStyle_number);
    printStringLn(" -> To calculate total number of students", TextStyle_body);

    printInt(5, TextStyle_number);
    printStringLn(" -> To delete student", TextStyle_body);

    printInt(6, TextStyle_number);
    printStringLn(" -> To show all students", TextStyle_body);

    printInt(0, TextStyle_number);
    printStringLn(" -> To exit", TextStyle_body);

    printString("\n---> Enter your choice: ", TextStyle_question);

    choice = readInt();

    switch (choice) {
        case 0:
            exit(0);
            break;
        case 1:
            navigatorPush(SCREEN_addStudent);
            break;
        case 2:
            navigatorPush(SCREEN_FindStudent);
            break;
        case 3:
            navigatorPush(SCREEN_SearchCourseId);
            break;
        case 4:
            navigatorPush(SCREEN_countStudents);
            break;
        case 5:
            navigatorPush(SCREEN_deleteStudent);
            break;
        case 6:
            navigatorPush(SCREEN_showAll);
            break;
        default: {
            printStringLn("Unknown Choice", TextStyle_error);
            delay_ms(1500);
            navigatorPushReplacement(SCREEN_home);
        }
    }
}