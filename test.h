
#ifndef TEST_H
#define TEST_H
#include <stdlib.h>
#include <stdio.h>

typedef struct 
{
	void* elems;
	int count;
	int capacity;
	int elementSize;
}Stack;

void stackNew(Stack * s, int capacity, int elementSize);
void stackDispose(Stack* s );
char stackEmpty(const Stack *s);
char stackPush(Stack *s, void* elem);
char stackPop(Stack* s, void* buff);
char stackTop(const Stack* s, void* buff);

#endif