//
// Created by asus on 2024-07-02.
//

#include <stdarg.h>
#include "input_output.h"

#include "stdio.h"
#include "../shared/delay_ms.h"

static char buffer[50];


static void setStyle(TextStyle textStyle) {
    switch (textStyle) {
        case TextStyle_label:
            //magenta
            printf("\033[1;35m");
            break;
        case TextStyle_body:
            //deafult
            printf("\033[0m");
            break;
        case TextStyle_number:
            //yellow
            printf("\033[1;33m");
            break;
        case TextStyle_question:
            //cyan
            printf("\033[1;36m");
            break;
        case TextStyle_error:
            //red
            printf("\033[1;31m");
            break;
    }
}

static void printAnimated(char *ptr, char *format, ...) {
    va_list args;
    va_start (args, format);
    int length, i = 0;

    length = sprintf(buffer, format, args);

    for (i = 0; i < length; ++i) {
        printf("%c", buffer[i]);
        delay_ms(5);
    }
}

void printString(char *ptr, TextStyle textStyle) {
    setStyle(textStyle);
    printAnimated("%s", ptr);
    setStyle(TextStyle_body);

}

void printStringLn(char *ptr, TextStyle textStyle) {
    printString(ptr, textStyle);
    printf("\n");
    setStyle(TextStyle_body);

}

void printInt(int number, TextStyle textStyle) {
    setStyle(textStyle);
    printf("%d", number);
    setStyle(TextStyle_body);

}

void printIntLn(int number, TextStyle textStyle) {
    printInt(number, textStyle);
    printf("\n");
    setStyle(TextStyle_body);

}

void printFloat(float number, TextStyle textStyle) {
    setStyle(textStyle);
    printf("%f", number);
    setStyle(TextStyle_body);

}

void printFloatLn(float number, TextStyle textStyle) {
    printFloat(number, textStyle);
    setStyle(TextStyle_body);

    printf("\n");
}


int readInt() {
    int x;
    scanf("%d", &x);
    return x;
}

void readString(char buffer[]) {
    scanf("%s", buffer);
}

float readFloat() {
    float x;
    scanf("%f", &x);
    return x;
}
