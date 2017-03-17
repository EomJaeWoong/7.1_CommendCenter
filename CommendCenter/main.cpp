#include <conio.h>
#include <stdio.h>
#include "Data.h"
#include "Queue.h"

int CreateUnit();
int CompleteCreate();
void PrintMessage();

void main()
{
	char commend;

	do{
		commend = '0';
		if (_kbhit()){
			commend = _getch();
		}

		if (commend == '1')
			CreateUnit();

		system("cls");
		PrintMessage();			// 메시지 출력

		CompleteCreate();	//완료된 유닛 제거

		Sleep(500);
	} while (commend != '2');
	printf("\n");
}

//유닛 생성
int CreateUnit()
{
	Data temp = { 0, GetTickCount() };
	Enque(&temp);

	return 0;
}

int CompleteCreate()
{
	int i;
	Data temp;
	if (!EmptyQueue()){
		for (i = 0; i < QueueSize(); i++){
			Peek(i + 1, &temp);
			if ((int)(((GetTickCount() - temp.tick) / CREATE_TIME) * 100) > 100){
				Deque(&temp);
			}
		}
	}
	return 0;
}

void PrintMessage()
{
	int i;
	Data temp;

	printf("------------ Commend Center --------------\n");
	printf("==========================================\n");
	printf("     1. 유닛 생성         2. 종료\n");
	printf("==========================================\n\n");

	printf("\t");
	for (i = 0; i < MAX - 1; i++)	printf("------ ");
	printf("\n");
	printf("\t");

	i = 1;
	while (Peek(i, &temp)){
		printf("|%3d%%| ", ((int)(((GetTickCount() - temp.tick) / CREATE_TIME) * 100)) <= 100 ?
			((int)(((GetTickCount() - temp.tick) / CREATE_TIME) * 100)) : 100);
		i++;
	}
	printf("\n");
	printf("\t");
	for (i = 0; i < MAX - 1; i++)	printf("------ ");
}