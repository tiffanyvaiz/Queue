#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct  node{
        struct node *next;
        int value;
 }node_t;

 typedef struct {
        int *front;
        int *rear;
        int size;
        node_t headNode;
 }queue_t;

/*題目規定功能*/
queue_t* CreateQueue(int);
bool isEmpty(queue_t*);
bool isFull (queue_t*);
queue_t* deQueue(queue_t*);
queue_t* enQueue(queue_t*,int);
queue_t* Clear(queue_t*);

/*自加FUNCTION*/ 
void OutputQueue(queue_t* sourceQueue);
int elementAmount(queue_t*);

#endif // QUEUE_H_INCLUDED
