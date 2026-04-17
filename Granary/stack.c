#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void initStack(Stack *s, int initialCapacity) {
    s->data = (int *)malloc(initialCapacity * sizeof(int));
    if (s->data == NULL) {
        exit(1);
    }
    s->capacity = initialCapacity;
    s->top = -1;
}

bool st_isEmpty(Stack *s) {
if (s->top == -1) {
    return true;
    } else{
            return false;}
}

bool st_isFull(Stack *s) {
    if (s->top == (s->capacity - 1)) {
    return true;
    } else{
            return false;}
}

void push(Stack *s, int value) {
    if (st_isFull(s)) {
        s->capacity *= 2;
        s->data = (int *)realloc(s->data, s->capacity * sizeof(int));
        if (s->data == NULL) {
            exit(1);
        }
    }
    s->top++;
    s->data[s->top] = value;
}

int pop(Stack *s) {
    if (st_isEmpty(s)) {
        return -1;
    }
    int value = s->data[s->top];
    s->top--;
    return value;
}

void destroyStack(Stack *s) {
    free(s->data);
    s->data = NULL;
    s->top = -1;
    s->capacity = 0;
}

int peek(Stack *s) {
    if (st_isEmpty(s)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return s->data[s->top];
}

int st_count(Stack *s){
    return (s->top+1);
}
