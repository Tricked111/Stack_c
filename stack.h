#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20

typedef struct
{
    char data[MAX_SIZE];

    int top_index;

} Stack;


void Stack_Init(Stack *);
void Stack_Push(Stack *,char);
char Stack_Pop(Stack *);
char Stack_Top(Stack *);
int Stack_NumEleme(Stack *);
int Stack_IsEmpty(Stack *);
void Stack_AllPrint(Stack *);