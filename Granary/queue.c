 #include "queue.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

queue* Create(unsigned int dydis) {
    queue* q = malloc(sizeof(queue));
    if (q == NULL) return NULL;
    q->data = malloc(dydis * sizeof(int));
    if (q->data == NULL) { free(q); return NULL; }
    q->max = dydis;
    q->n   = 0;
    return q;
}

void Done(queue* q) {
    if (q == NULL) return;
    free(q->data);
    free(q);
}

void enqueue(queue* q, int reiksme) {
    if (q == NULL || isFull(q)) return;
    q->data[q->n++] = reiksme;
}
//FIFO
int dequeue(queue* q) {
    if (q == NULL || isEmpty(q)) return 0;
    int pirmas = q->data[0];
    unsigned int i;
    for (i = 0; i < q->n - 1; i++)
        q->data[i] = q->data[i + 1];
    q->n--;
    return pirmas;
}

unsigned int count(queue* q) {
    if (q == NULL) return 0;
    return q->n;
}

unsigned int isEmpty(queue* q) {
    return count(q) == 0;
}

unsigned int isFull(queue* q) {
    if (q == NULL) return 0;
    return q->n == q->max;
}

queue* clone(queue* q) {
    if (q == NULL) return NULL;
    queue* nauja = Create(q->max);
    if (nauja == NULL) return NULL;
    memcpy(nauja->data, q->data, q->n * sizeof(int));
    nauja->n = q->n;
    return nauja;
}

void makeEmpty(queue* q) {
    if (q != NULL) q->n = 0;
}

char* toString(queue* q) {
    static char buf[256];
    if (q == NULL || isEmpty(q)) {
        strcpy(buf, "[ tuscia ]");
        return buf;
    }
    unsigned int i;
    int pos = 0;
    pos += sprintf(buf + pos, "[ ");
    for (i = 0; i < q->n && i < 10; i++)
        pos += sprintf(buf + pos, "%d ", q->data[i]);
    if (q->n > 10)
        pos += sprintf(buf + pos, "... ");
    sprintf(buf + pos, "]");
    return buf;
}
