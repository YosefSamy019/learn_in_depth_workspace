//
// Created by asus on 2024-07-02.
//

#ifndef MAIN_C_INPUT_OUTPUT_H
#define MAIN_C_INPUT_OUTPUT_H

typedef enum {
    TextStyle_label,
    TextStyle_body,
    TextStyle_number,
    TextStyle_question,
    TextStyle_error,
} TextStyle;

void printString(char *ptr, TextStyle textStyle);

void printStringLn(char *ptr, TextStyle textStyle);

void printInt(int number, TextStyle textStyle);

void printIntLn(int number, TextStyle textStyle);

void printFloat(float number, TextStyle textStyle);

void printFloatLn(float number, TextStyle textStyle);

int readInt();

void readString(char buffer[]);

float readFloat();

#endif //MAIN_C_INPUT_OUTPUT_H
