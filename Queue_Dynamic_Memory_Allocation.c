
#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
struct Node{
	int iData;
	struct Node *ptrNext;
};
typedef struct Node QueueNode;
QueueNode *front=NULL,*rear=NULL;
void fnQInsertion(int);
int fnQDelete();
void fnQDisplay();
int fnQEmpty();
void fnQInsertion(int iData)
{
	QueueNode *ptrNewNode;
	ptrNewNode=(QueueNode*) malloc(sizeof(QueueNode));
	ptrNewNode->iData=iData;
	ptrNewNode->ptrNext=NULL;
	if(fnQEmpty()==TRUE)
	front=rear=ptrNewNode;
	else
	{
		rear->ptrNext=ptrNewNode;
		rear=ptrNewNode;
	}
}
int fnQDelete()
{
	int iData;
	QueueNode *ptrDeleteNode;
	if(fnQEmpty()==TRUE)
	{
		printf("queue is empty\n");
		return 0;
	}
	else
	{
		iData=front->iData;
		ptrDeleteNode=front;
		front=front->ptrNext;
		free(ptrDeleteNode);
		return(iData);
	}
}
void fnQDisplay()
{
	QueueNode *ptrDisplayNode;
	if(fnQEmpty()==TRUE)
	printf("nothing to display\n");
	else
	{
		ptrDisplayNode=front;
		while(ptrDisplayNode!=NULL)
		{
			printf("%d\n",ptrDisplayNode->iData);
			ptrDisplayNode=ptrDisplayNode->ptrNext;
		}
	}
}
int fnQEmpty()
{
	if(front==NULL||rear==NULL)
	return TRUE;
	else
	return FALSE;
}
int main()
{
   int iChoice,iData;
    do
{
	printf("1. Insertion\n");
	printf("2. Deletion\n");
	printf("3. Display\n");
	printf("4. Exit\n");
	printf("Enter your choice\n");
	scanf("%d",&iChoice);
	switch(iChoice)
	{
		case 1:
			printf("enter the element");
			scanf("%d",&iData);
			fnQInsertion(iData);
			break;
		case 2:
			if(fnQEmpty()==TRUE)
			printf("queue is empty\n");
			else
			printf("item deleted=%d\n",fnQDelete());
			break;
		case 3:
			fnQDisplay();
			break;
		case 4:
			exit(1);
		default:
			printf("wrong choice\n");
	}
}
  while(1);
}