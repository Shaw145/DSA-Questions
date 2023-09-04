#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 3
#define TRUE 1
#define FALSE 0
void fnQInsertion(int[],int);
int fnQDeletion(int[]);
void fnQDisplay(int[]);
int fnQFull();
int fnQEmpty();
int rear=-1;
int front=-1;
void fnQInsertion(int arrQUEUE[],int data)
{
	if(fnQFull()==1)
	{ 
		printf("Queue is Full\n");
	}
	else
	{
		if(front==-1)
		    front=0;
		rear=(rear+1)%MAXSIZE;
		arrQUEUE[rear]=data;
	}
}
int fnQDeletion(int arrQUEUE[])
{
	int data;
	if(fnQEmpty()==1)
	{
		return -1;
	}
	else
	{
		data=arrQUEUE[front];
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else
		{
			front=(front+1)%MAXSIZE;
		}
		return data;
	}
}
void fnQDisplay(int arrQUEUE[])
{
	int counter;
	if(fnQEmpty()==1)
	{
		printf("Nothing to display\n");
	}
	else
	{
		
		for(counter=front;counter!=rear;counter = ((counter+1)%MAXSIZE)) // ******************************
		    printf("%d\n",arrQUEUE[counter]);
		    
		printf("%d\n",arrQUEUE[rear]); // ******************************
	}
}
int fnQFull()
{
	if(((rear+1)%MAXSIZE) == front) // **************************** // *************************** //
	  return 1;
	else
	  return 0;
}
int fnQEmpty()
{
	if(front==-1 && rear == -1)
	  return 1;
	else
	  return 0;
}
int main()
{
	int arrQUEUE[30],choice,data;
	printf("1.Insertion\n");
	printf("2.Deletion\n");
	printf("3.Display\n");
	printf("4.Exit\n");
	do
	{
		
		printf("Enter the choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the Element : ");
				scanf("%d",&data);
				fnQInsertion(arrQUEUE,data);
				break;
		    case 2:
		    	data=fnQDeletion(arrQUEUE);
		    	if(data==-1)
		    	{
		    	  printf("queue is empty\n");
		        }
		    	else
		    	{
				  printf("item delete=%d\n",data);
				}  
		    	break;
		    case 3:
		    	fnQDisplay(arrQUEUE);
		    	break;
		    case 4:
		    	exit(1);
		}
	}
	while(1);
}