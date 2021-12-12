#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

////////////////CREATE//////////////

Stack * Stack_Create (){
    Stack *stack;
    stack = (Stack*) malloc(sizeof(Stack));
    Stack_Init(stack);
    return stack;
}


////////////////MAIN FUNCTION/////////////////
void Stack_Init(Stack *stack){
    stack->top_index = 0;
}

int Stack_IsEmpty(Stack *stack){
    if(stack->top_index == 0) return 1;
    else
    return 0;
}

void Stack_Push(Stack *stack,char data){
    if(stack->top_index < MAX_SIZE){
        stack->data[stack->top_index] = data;
        stack->top_index++;
    }
    else{
    printf("STACK IS FULL\n");
    return;
    }
}

char Stack_Pop(Stack *stack){
    if(!Stack_IsEmpty(stack)){
       stack->top_index--; 
       return stack->data[stack->top_index];  
    }
    return 0;
}

char Stack_Top(Stack *stack){
    if(!Stack_IsEmpty(stack)){
        return stack->data[stack->top_index-1];
    }
    return 0;
}

int Stack_NumEleme(Stack *stack){
    return stack->top_index;
}

void Stack_AllPrint(Stack *stack){
    if(Stack_IsEmpty(stack)) return;
    printf("Elements in stack: \n");
    for(int i = stack->top_index-1;i>=0;i--){
    printf("    ---------\n %.2d |   %c   |\n",i,stack->data[i]);
    }
    printf("    ---------\n");
    
}



void Stack_Print(Stack *stack){
    if(Stack_IsEmpty(stack)) return;
    printf("Elements in stack: ");
    for(int i = 0;i<stack->top_index;i++){
    printf("%c",stack->data[i]);
    }
    printf("\n");
    
}


/////////////////////TESTY//////////////////////

void Check_Stack_Init(Stack *stack){
    Stack_Init(stack);
    printf("Stack is init!\n");
}


void Check_Stack_IsEmpty(Stack *stack){
    if(Stack_IsEmpty(stack)) printf("Stack is empty\n");
    else
        printf("The stack is not empty\n");
}


void Check_Stack_Push(Stack *stack,int data){
    Stack_Push(stack,data);
    printf("Stack_PUSH: %c\n",data);
}


void Check_Stack_Pop(Stack *stack){
    int data = Stack_Pop(stack);
    printf("Stack_POP: %c\n",data);
}

void Check_Stack_Top(Stack* stack){
    int data = Stack_Top(stack);
    printf("Stack_TOP: %c\n",data);
}

void Check_Stack_NumEleme(Stack *stack){
    int num = Stack_NumEleme(stack);
    printf("Number of elements: %c\n",num);
}


///////////////STRING AND ARGV////////////////


void String_in_Stack(Stack * stack,char *string){
    for(int i = 0;string[i] != '\0';i++){
        Stack_Push(stack,string[i]);
    }
}

void Argv_in_Stack(Stack *stack,char *argv[],int argc){
    for(int i = 1;i < argc;i++){
        String_in_Stack(stack,argv[i]);
    }
}

////////////////SEARCH IN STACK/////////////////////

int Exist_in_Stack(Stack *stack,char data){
    if(!Stack_IsEmpty(stack)){
    for(int i = stack->top_index-1;i>=0;i--){
        if(stack->data[i] == data)
        return 1;
        }
    }
    return 0;
}

int Search_in_Stack(Stack *stack,char data){
    if(Exist_in_Stack(stack,data)){
        for(int i = stack->top_index-1;i>=0;i--){
        if(stack->data[i] == data)
        return i;
        }
    }
    return -1;
}
