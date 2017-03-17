#include "Queue.h"
#include "Data.h"

Data Queue[MAX];
int read, write;

int readValue(){	return read;	}

void InitQueue()
{
	read = 0;
	write = 0;
}

int EmptyQueue()
{
	if (read == write)	return 1;
	else				return 0;
}

int FullQueue()
{
	if (read == ((write + 1) >= MAX? write - MAX + 1 : write + 1))
			return 1;
	else
		return 0;
}

int Enque(Data *Data)
{
	if (!FullQueue()){
		Queue[write] = *Data;
		write = (write + 1) % MAX;
		return 1;
	}
	else	return 0;
}

int Deque(Data *Data)
{
	if (!EmptyQueue()){
		*Data = Queue[read];
		read = (read + 1) % MAX;
		return 1;
	}
	else return 0;
}

int Peek(int position, Data *Data)
{
	if ((position != 0) && (position <= QueueSize())){
		*Data = Queue[read + position - 1];
		return 1;
	}
	else return 0;
}

int QueueSize()
{
	int Size = ((write + 1) > MAX ? write + MAX : write) - read;
	return Size;
}