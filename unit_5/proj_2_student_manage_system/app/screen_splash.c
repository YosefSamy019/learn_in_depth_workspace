//
// Created by asus on 2024-07-02.
//
#include "navigator.h"
#include "input_output.h"
#include "../shared/delay_ms.h"

SCREEN_DEFINE(SCREEN_splash) {

    printStringLn("Proj:\t\tProject no 2, student management system", TextStyle_label);
    printStringLn("Name:\t\tYoussef Samy Youssef", TextStyle_label);
    printStringLn("Course:\t\tLearn in depth", TextStyle_label);
    printStringLn("Instructor:\tEng. Keroles Khalil", TextStyle_label);

    char i = 0;
    printString("\nLoad: ", TextStyle_body);
    for (char i = 0; i < 5; ++i) {
        printString(".", TextStyle_body);
        delay_ms(700);
    }

    navigatorPush(SCREEN_home);

}
