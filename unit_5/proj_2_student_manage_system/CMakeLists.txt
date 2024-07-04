cmake_minimum_required(VERSION 3.23)
project(unit_5 C)

set(CMAKE_C_STANDARD 99)

add_executable(unit_5 main.c shared/delay_ms.c shared/delay_ms.h app/input_output.c app/input_output.h shared/debug.h shared/models.h data/linked_list.c data/linked_list.h app/navigator.c app/navigator.h app/screen_splash.c app/sceen_home.c app/sceen_addStudent.c app/sceen_findStudent.c app/sceen_searchCourseId.c app/sceen_countStudents.c app/sceen_updateStudents.c app/sceen_showAll.c app/screen_deleteStudent.c file_io/file_io.c file_io/file_io.h)
