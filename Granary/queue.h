#ifndef QUEUE_H
#define QUEUE_H

/* Eiles duomenu struktura */
typedef struct {
    int*         data;
    unsigned int max;
    unsigned int n;
} queue;

/* Sukuria nauja tuscia eile */
queue*       Create   (unsigned int dydis);

/* Sunaikina eile ir islaisvina atminti */
void         Done     (queue* q);

/* Ideda elementa i eiles gala */
void         enqueue  (queue* q, int reiksme);

/* Isima elementa is eiles pradþios */
int          dequeue  (queue* q);

/* Grazina elementu kieki */
unsigned int count    (queue* q);

/* Tikrina ar eile tuscia */
unsigned int isEmpty  (queue* q);

/* Tikrina ar eile pilna */
unsigned int isFull   (queue* q);

/* Sukuria eiles kopija */
queue*       clone    (queue* q);

/* Isivalo eile (neislaisvina atminties) */
void         makeEmpty(queue* q);

/* Grazina eile kaip teksta */
char*        toString (queue* q);

#endif
