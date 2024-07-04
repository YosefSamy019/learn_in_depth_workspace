//
// Created by asus on 2024-07-02.
//

#include <stdlib.h>
#include "navigator.h"
#include "input_output.h"
#include "../shared/delay_ms.h"
#include "../data/linked_list.h"

SCREEN_DEFINE(SCREEN_SearchCourseId) {
    int id = 0, choice = 0;
    unsigned int allStudentsCount = LINKED_getCount();
    unsigned int registeredStudentsCount = 0;
    Student buffer[allStudentsCount];
    LINKED_Status status;

    printString("\n---> Enter course ID to get students registered in: ", TextStyle_question);

    id = readInt();

    registeredStudentsCount = LINKED_getStudentsInCourse(id, buffer);

    if (registeredStudentsCount == 0) {
        printStringLn("Not found\n\n", TextStyle_error);
    } else {
        int i, j;

        for (i = 0; i < registeredStudentsCount; ++i) {
            printString("first Name: ", TextStyle_label);
            printString(buffer[i].firstName, TextStyle_body);
            printString("\n", TextStyle_body);

            printString("last Name: ", TextStyle_label);
            printString(buffer[i].lastName, TextStyle_body);
            printString("\n", TextStyle_body);

            printString("Roll ID: ", TextStyle_label);
            printInt(buffer[i].rollId, TextStyle_number);
            printString("\n", TextStyle_body);

            printString("GPA: ", TextStyle_label);
            printFloat(buffer[i].gpa, TextStyle_number);
            printString("\n", TextStyle_body);

            printString("Courses ID: ", TextStyle_label);
            for (j = 0; j < 5; ++j) {
                printInt(buffer[i].coursesId[j], TextStyle_number);
                printString(" ", TextStyle_label);
            }
            printString("\n\n", TextStyle_body);
        }
    }

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
        navigatorPushReplacement(SCREEN_SearchCourseId);
    }

}