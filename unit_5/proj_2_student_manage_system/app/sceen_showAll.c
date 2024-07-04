//
// Created by asus on 2024-07-02.
//
#include "navigator.h"
#include "input_output.h"
#include "../shared/delay_ms.h"
#include "../shared/models.h"
#include "../shared/debug.h"
#include "../data/linked_list.h"

SCREEN_DEFINE(SCREEN_showAll) {
    unsigned int count = LINKED_getCount();
    unsigned int i, j, choice;

    printStringLn("Show all students:\n", TextStyle_label);


    if (count <= 0) {
        printStringLn("The database is empty\n\n", TextStyle_error);
    } else {
        Student list[count];
        LINKED_getAllStudents(list);

        for (i = 0; i < count; i++) {
            printString("first Name: ", TextStyle_label);
            printString(list[i].firstName, TextStyle_body);
            printString("\n", TextStyle_body);

            printString("last Name: ", TextStyle_label);
            printString(list[i].lastName, TextStyle_body);
            printString("\n", TextStyle_body);

            printString("Roll ID: ", TextStyle_label);
            printInt(list[i].rollId, TextStyle_number);
            printString("\n", TextStyle_body);

            printString("GPA: ", TextStyle_label);
            printFloat(list[i].gpa, TextStyle_number);
            printString("\n", TextStyle_body);

            printString("Courses ID: ", TextStyle_label);
            for (j = 0; j < 5; ++j) {
                printInt(list[i].coursesId[j], TextStyle_number);
                printString(" ", TextStyle_label);
            }
            printString("\n\n", TextStyle_body);
        }
    }


    printString("\n---> Enter 0 to return to previous screen: ", TextStyle_question);
    choice = readInt();

    if (choice == 0) {
        navigatorPop();
    } else {
        navigatorPushReplacement(SCREEN_showAll);
    }
}