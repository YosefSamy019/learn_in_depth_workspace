//
// Created by asus on 2024-07-02.
//

#include <stdlib.h>
#include "navigator.h"
#include "../shared/debug.h"
#include "input_output.h"

void (*(screenPtrStack[10]))();

enum Screens screensStack[10];

static char count = 0;

static void printScreen(enum Screens screen, TextStyle textStyle) {
    switch (screen) {
        case SCREEN_splash: {
            printString("Splash", textStyle);
            break;
        }
        case SCREEN_home: {
                printString("Home", textStyle);

            break;
        }
        case SCREEN_addStudent: {
            printString("Add Student", textStyle);


            break;
        }
        case SCREEN_FindStudent: {
            printString("Find Student", textStyle);

            break;
        }
        case SCREEN_SearchCourseId: {
            printString("Search Course ID", textStyle);

            break;
        }
        case SCREEN_countStudents: {
            printString("Count Students", textStyle);

            break;
        }
        case SCREEN_updateStudents: {
            printString("Update Student", textStyle);

            break;
        }
        case SCREEN_showAll: {
            printString("Show all", textStyle);

            break;
        }
        case SCREEN_deleteStudent: {
            printString("Delete Students", textStyle);

            break;
        }
        default:
            return;
    }

}

static void printHeader() {
    if (count == 0) return;
    int i;

    printStringLn("---------------------------------", TextStyle_label);

    printString(" PATH: ", TextStyle_label);
    for (i = 0; i < count; ++i) {
        printString(" >", TextStyle_label);
        printScreen(screensStack[i], TextStyle_question);
    }

    printStringLn("\n---------------------------------\n", TextStyle_label);


}

void navigatorPush(enum Screens screen) {


    if (count >= 5) {
        PRINT_DEBUG("Screen Stack is full", 0);
    } else {
        screensStack[count] = screen;

        switch (screen) {
            case SCREEN_splash: {
                screenPtrStack[count] = SCREEN(SCREEN_splash);
                break;
            }
            case SCREEN_home: {
                screenPtrStack[count] = SCREEN(SCREEN_home);
                break;
            }
            case SCREEN_addStudent: {
                screenPtrStack[count] = SCREEN(SCREEN_addStudent);

                break;
            }
            case SCREEN_FindStudent: {
                screenPtrStack[count] = SCREEN(SCREEN_FindStudent);
                break;
            }
            case SCREEN_SearchCourseId: {
                screenPtrStack[count] = SCREEN(SCREEN_SearchCourseId);
                break;
            }
            case SCREEN_countStudents: {
                screenPtrStack[count] = SCREEN(SCREEN_countStudents);
                break;
            }
            case SCREEN_updateStudents: {
                screenPtrStack[count] = SCREEN(SCREEN_updateStudents);
                break;
            }
            case SCREEN_showAll: {
                screenPtrStack[count] = SCREEN(SCREEN_showAll);
                break;
            }
            case SCREEN_deleteStudent: {
                screenPtrStack[count] = SCREEN(SCREEN_deleteStudent);
                break;
            }
            default:
                return;
        }
        //clear old console

        system("cls");
        count++;

        //call screen
        printHeader();

        PRINT_DEBUG("call screen: %d", screen);

        screenPtrStack[count - 1]();
    }
}

void navigatorPushReplacement(enum Screens screen) {
    if (count == 0) {
        PRINT_DEBUG("Screen Stack is empty", 0);
    } else {
        screensStack[count - 1] = screen;

        switch (screen) {
            case SCREEN_splash: {
                screenPtrStack[count - 1] = SCREEN(SCREEN_splash);
                break;
            }
            case SCREEN_home: {
                screenPtrStack[count - 1] = SCREEN(SCREEN_home);
                break;
            }
            case SCREEN_addStudent: {
                screenPtrStack[count - 1] = SCREEN(SCREEN_addStudent);

                break;
            }
            case SCREEN_FindStudent: {
                screenPtrStack[count - 1] = SCREEN(SCREEN_FindStudent);
                break;
            }
            case SCREEN_SearchCourseId: {
                screenPtrStack[count - 1] = SCREEN(SCREEN_SearchCourseId);
                break;
            }
            case SCREEN_countStudents: {
                screenPtrStack[count - 1] = SCREEN(SCREEN_countStudents);
                break;
            }
            case SCREEN_updateStudents: {
                screenPtrStack[count - 1] = SCREEN(SCREEN_updateStudents);
                break;
            }
            case SCREEN_showAll: {
                screenPtrStack[count - 1] = SCREEN(SCREEN_showAll);
                break;
            }
            case SCREEN_deleteStudent: {
                screenPtrStack[count] = SCREEN(SCREEN_deleteStudent);
                break;
            }
            default:
                return;
        }
        //clear old console

        system("cls");

        //call screen
        printHeader();

        PRINT_DEBUG("call screen: %d", screen);

        screenPtrStack[count - 1]();
    }
}


void navigatorPop() {
    if (count == 0) {
        PRINT_DEBUG("Screen Stack is empty", 0);
    } else {
        //clear old console
        system("cls");

        count--;


        //call screen
        printHeader();
        PRINT_DEBUG("pop from previous screen: %d", 0);

        screenPtrStack[count - 1]();
    }
}

