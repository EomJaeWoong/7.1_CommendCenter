#ifndef QUEUE_H
#define QUEUE_H
#include "Data.h"
#define MAX 6

int readValue();
void InitQueue();
int EmptyQueue();
int FullQueue();
int Enque(Data *Data);
int Deque(Data *Data);
int Peek(int position, Data *Data);
int QueueSize();

#endif