#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PriorityQueue.h"
#define CHLEN 20

int DataPriorityComp(char ch1[], char ch2[])
{
	return strlen(ch2) - strlen(ch1);
}

int main(void)
{
	char* buff;
	PQueue pq;
	PQueueInit(&pq, DataPriorityComp);

	buff = (char*)malloc(CHLEN);
	scanf_s("%s", buff, CHLEN - 1);
	PEnqueue(&pq, buff);
	buff = (char*)malloc(CHLEN);
	scanf_s("%s", buff, CHLEN - 1);
	PEnqueue(&pq, buff);
	buff = (char*)malloc(CHLEN);
	scanf_s("%s", buff, CHLEN - 1);
	PEnqueue(&pq, buff);
	printf("%s \n", buff = PDequeue(&pq));
	free(buff);

	buff = (char*)malloc(CHLEN);
	scanf_s("%s", buff, CHLEN - 1);
	PEnqueue(&pq, buff);
	buff = (char*)malloc(CHLEN);
	scanf_s("%s", buff, CHLEN - 1);
	PEnqueue(&pq, buff);
	buff = (char*)malloc(CHLEN);
	scanf_s("%s", buff, CHLEN - 1);
	PEnqueue(&pq, buff);
	printf("%s \n", buff = PDequeue(&pq));
	free(buff);

	while (!PQIsEmpty(&pq))
	{
		printf("%s \n", buff = PDequeue(&pq));
		free(buff);
	}

	return 0;
}
