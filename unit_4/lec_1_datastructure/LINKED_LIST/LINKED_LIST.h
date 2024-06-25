#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED


struct SData{
    int id;
    char name[40];
    float height;
};

struct SStudent{
    struct SData data;
    struct SStudent * pNext;
};

void AddStudent();
int DeleteStudent();
void DisplayAll();
void DeleteAll();
void Reverse();
void GetNthNode();
void GetMiddle();
void GetLengthIterate();
void GetLengthRecursive();
#endif // LINKED_LIST_H_INCLUDED
