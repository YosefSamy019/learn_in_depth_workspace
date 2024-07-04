//
// Created by asus on 2024-07-03.
//

#ifndef MAIN_C_FILE_IO_H
#define MAIN_C_FILE_IO_H


#define FILE_NAME "../students.txt"

#include "../shared/models.h"

int FILE_read(void (*callBack)(Student *student));

#endif //MAIN_C_FILE_IO_H
