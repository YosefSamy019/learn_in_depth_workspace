#include <stdio.h>
#include <stdlib.h>

#include "LINKED_LIST.h"

int main()
{


    do
    {
        printf("Enter:-\n");
        printf("0: add student\n");
        printf("1: remove student\n");
        printf("2: display all\n");
        printf("3: delete all\n");
        printf("4: reverse\n");
        printf("5: get nTh node\n");
        printf("6: get middle\n");
        printf("7: get Length Iterate\n");
        printf("8: get Length Recursive\n");

        int i,temp;

        printf("--> ");
        scanf("%d",&i);

        switch(i)
        {
        case 0:
            AddStudent();
            break;
        case 1:
            temp = DeleteStudent();
            printf((temp == 1)? "Deleted\n" : "NotFound\n" );
            break;
        case 2:
            DisplayAll();
            break;
        case 3:
            DeleteAll();
            break;
        case 4:
            Reverse();
            break;
        case 5:
            GetNthNode();
            break;
        case 6:
            GetMiddle();
            break;
        case 7:
            GetLengthIterate();
            break;
        case 8:
            GetLengthRecursive();
            break;
        default:
            printf("Unsupported\n");
            break;
        }


        printf("-------------\n");
        printf("Press Enter to return to menu");
        getch();
        system("cls"); // For Windows use system("cls");

    }
    while(1);
    return 0;
}
