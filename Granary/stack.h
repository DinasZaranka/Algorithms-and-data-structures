#ifndef STACK_H
#define STACK_H
#include <stdbool.h>

typedef struct {
    int *data;
    int top;
    int capacity;
} Stack;

void initStack(Stack *s, int initialCapacity);
bool st_isEmpty(Stack *s);
bool st_isFull(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
int peek(Stack *s);
void destroyStack(Stack *s);
int st_count(Stack *s);
#endif
