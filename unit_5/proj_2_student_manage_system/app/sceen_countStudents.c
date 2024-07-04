//
// Created by asus on 2024-07-02.
//
#include "navigator.h"
#include "input_output.h"
#include "../shared/delay_ms.h"
#include "../shared/models.h"
#include "../shared/debug.h"
#include "../data/linked_list.h"

SCREEN_DEFINE(SCREEN_countStudents) {
    unsigned int count = 0;

    printString("The total number of students is: ", TextStyle_label);

    count = LINKED_getCount();

    printInt(count, TextStyle_number);


    printStringLn("\n\nPlease Choose what you want to perform:", TextStyle_label);

    printInt(1, TextStyle_number);
    printStringLn(" -> To refresh screen", TextStyle_body);

    printInt(0, TextStyle_number);
    printStringLn(" -> To return screen", TextStyle_body);

    printString("Choice: ", TextStyle_question);
    int choice = readInt();

    switch (choice) {
        case 0:
            navigatorPop();
            break;
        case 1:
            navigatorPushReplacement(SCREEN_countStudents);
            break;
        default:
            navigatorPushReplacement(SCREEN_countStudents);
            break;
    }

}