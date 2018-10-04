#include "stack.h"
#include <string.h>

void stackNew(Stack* s, int capacity, int elementSize){
	s->elems = malloc(capacity* elementSize);
	s->count = 0;
	s->capacity = capacity;
	s->elementSize = elementSize;
}

void stackDispose(Stack * s){
	free(s->elems);
	s->count=0;
	s->capacity=0;
	s->elementSize=0;
	s->elems=NULL;
}

char stackEmpty(const Stack* s){
	return s->count==0;
}

char stackPush(Stack* s, void* elem){
	if(s->count == s->capacity)
	{
		s->capacity *=2;

		s->elems = realloc(s->elems, s->capacity*s->elementSize);
		if(!s->elems)
			return 0;
	}
	memcpy((char*)s->elems + s->count*s->elementSize, elem, s->elementSize);
	s->count++;
	return 1;
}

char stackPop(Stack* s, void* buff){
	
	if(stackEmpty(s))
		return 0;
	
	s->count--;
	if(buff)
		memcpy(buff,(char*) s->elems + s->count * s->elementSize , s->elementSize);
	return 1;
}

char stackTop(const Stack* s, void *buff){
	if(stackEmpty(s))
		return 0;
	memcpy(buff,(char*)s->elems + (s->count-1) * s->elementSize , s->elementSize);
	return 1;
}

int main()
{
	Stack s;
	stackNew(&s, 4, sizeof(int));
	int i = 8;
	stackPush(&s, &i);
	i=9;
	stackPush(&s, &i);
	i=10;
	stackPush(&s, &i);
	int buff;
	stackPop(&s,&buff);
	stackPop(&s,0);
	stackPop(&s,&buff);
	stackPop(&s,&buff);
	stackDispose(&s);
	
	return 0;
}

