
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 50;
struct Node{
	int iData;
	struct Node *ptrNext;
};
typedef struct Node StackNode;
StackNode *top=NULL;
void fnPush(int);
int fnPop();
void fnDisplay();
int fnEmpty();
void fnPush(int iData)
{
	StackNode *ptrNewNode;
	ptrNewNode=(StackNode*) malloc(sizeof(StackNode));
	ptrNewNode->iData=iData;
	ptrNewNode->ptrNext=top;
	top=ptrNewNode;
}
int fnPop()
{
	int iData;
	StackNode *ptrDeleteNode;
	if(fnEmpty()==1)
	return -1;
	else
	{
		iData=top->iData;
		ptrDeleteNode=top;
		top=top->ptrNext;
		free(ptrDeleteNode);
		return(iData);
	}
}
void fnDisplay()
{
	StackNode *ptrDisplayNode;
	if(fnEmpty()==1)
	printf("there is nothing to display\n");
	else
	{
		ptrDisplayNode=top;
		while(ptrDisplayNode!=NULL)
		{
			printf("%d\n",ptrDisplayNode->iData);
			ptrDisplayNode=ptrDisplayNode->ptrNext;
		}
	}
}
int fnEmpty()
{
	if(top==NULL)
	return 1;
	else
	return 0;
}
int main()
{
   int iChoice,iData;
    do
{
	printf("1. Push\n");
	printf("2. Pop\n");
	printf("3. Display\n");
	printf("4. Exit\n");
	printf("Enter your choice\n");
	scanf("%d",&iChoice);
	switch(iChoice)
	{
		case 1:
			printf("enter the element : ");
			scanf("%d",&iData);
			fnPush(iData);
			break;
		case 2:
			iData=fnPop();
			if(iData==1)
			printf("stack is empty\n");
			else
			printf("item deleted=%d\n",iData);
			break;
		case 3:
			fnDisplay();
			break;
		case 4:
			exit(1);
	}
}
  while(1);
}