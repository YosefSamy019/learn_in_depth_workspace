//
// Created by asus on 2024-07-03.
//

#include <stdio.h>
#include "file_io.h"

#include "../shared/models.h"
#include "../shared/debug.h"

int FILE_read(void (*callBack)(Student *student)) {
    int scanVal = 0, studentsCount = 0;
    Student tempStudent;
    FILE *fptr;

    fptr = fopen(FILE_NAME, "r");

    if (fptr == 0) {
        PRINT_DEBUG("Failed to open file", 0);
    } else {
        do {
            scanVal = 0;
            scanVal += fscanf(fptr, "%d", &tempStudent.rollId);
            scanVal += fscanf(fptr, "%s", tempStudent.firstName);
            scanVal += fscanf(fptr, "%s", tempStudent.lastName);
            scanVal += fscanf(fptr, "%f", &tempStudent.gpa);
            scanVal += fscanf(fptr, "%d", tempStudent.coursesId + 0);
            scanVal += fscanf(fptr, "%d", tempStudent.coursesId + 1);
            scanVal += fscanf(fptr, "%d", tempStudent.coursesId + 2);
            scanVal += fscanf(fptr, "%d", tempStudent.coursesId + 3);
            scanVal += fscanf(fptr, "%d", tempStudent.coursesId + 4);

            if (scanVal == 9) {
                //student is read successfully
                callBack(&tempStudent);
            }

        } while (scanVal == 9);

        fclose(fptr);
    }

    return studentsCount;
}