#include <stdio.h>
#include "shared/debug.h"

#include "data/linked_list.h"

#include "app/navigator.h"


int main() {
    //register dummy data if debug mode is on
    if (ENABLE_DEBUG != 0) {
        Student s1 = {"Joe", "Samy", 1, 3.5, {1, 2, 3, 4, 5}};
        Student s2 = {"ahmed", "omar", 2, 4, {1, 2, 3, 4, 5}};
        Student s3 = {"ali", "nour", 3, 2, {1, 2, 3, 4, 5}};
        Student s4 = {"Abdo", "abdo", 4, 12, {6, 7, 8, 9, 10}};

        LINKED_addStudentManual(s1);
        LINKED_addStudentManual(s2);
        LINKED_addStudentManual(s3);
        LINKED_addStudentManual(s4);
    }

    navigatorPush(SCREEN_splash);


    printf("\n\n--> Program finished <--\n\n");
    getchar();

    return 0;
}


