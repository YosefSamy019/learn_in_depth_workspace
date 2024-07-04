//
// Created by asus on 2024-07-02.
//

#ifndef MAIN_C_NAVIGATOR_H
#define MAIN_C_NAVIGATOR_H

#define SCREEN_DEFINE(_screen_) void screen_##_screen_()
#define SCREEN(_screen_)  screen_##_screen_

enum Screens {
    SCREEN_splash,
    SCREEN_home,
    SCREEN_addStudent,
    SCREEN_FindStudent,
    SCREEN_SearchCourseId,
    SCREEN_countStudents,
    SCREEN_updateStudents,
    SCREEN_showAll,
    SCREEN_deleteStudent,
};

//functions
void navigatorPush(enum Screens screen);

void navigatorPushReplacement(enum Screens screen);

void navigatorPop();

//screens

SCREEN_DEFINE(SCREEN_splash);

SCREEN_DEFINE(SCREEN_home);

SCREEN_DEFINE(SCREEN_addStudent);

SCREEN_DEFINE(SCREEN_FindStudent);

SCREEN_DEFINE(SCREEN_SearchCourseId);

SCREEN_DEFINE(SCREEN_countStudents);

SCREEN_DEFINE(SCREEN_updateStudents);

SCREEN_DEFINE(SCREEN_showAll);

SCREEN_DEFINE(SCREEN_deleteStudent);

#endif //MAIN_C_NAVIGATOR_H
