#include "LinkedList.h"


void LInsert(Node** head, Node** tail, int Data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = Data;
	newNode->next = NULL;
	if (*tail == NULL)
		*tail = newNode;
	else
		newNode->next = *head;
	*head = newNode;
}

void LRead(Node* head)
{
	if (head == NULL)
	{
		printf("저장된 자연수가 존재하지 않습니다. \n");
	}
	else
	{
		Node* cur = head;
		printf("%d ", cur->data);
		while (cur->next != NULL)
		{
			cur = cur->next;
			printf("%d ", cur->data);
		}
		printf("\n");
	}
}

int LRemove(Node* head, Node* tail)
{
	if (head == NULL)
	{
		return 0;
	}
	else
	{
		Node* delNode = head;
		Node* delNextNode = head->next;
		printf("%d을(를) 삭제합니다. \n", head->data);
		free(delNode); // 첫 번째 Node삭제
		while (delNextNode != NULL) // 두 번째 이후 Node 삭제
		{
			delNode = delNextNode;
			delNextNode = delNextNode->next;
			printf("%d을(를) 삭제합니다. \n", delNode->data);
			free(delNode);
		}
	}
}