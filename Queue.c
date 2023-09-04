#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 3
#define TRUE 1
#define FALSE 0



void QInsertion(int[], int);
int QDeletion(int[]);
void QDisplay(int[]);
int fnQFull();
int fnQEmpty();
int front = -1, rear = -1;


void QInsertion(int arrQueue[],int data){
    if(fnQFull() == 1)
        printf("Queue is Full.\n"); 
    
    else{
        if (front == -1)
            front =0;
         
        rear = rear+1;
        arrQueue[rear] = data;
    }
}

int QDeletion(int arrQueue[]){
    int data;
    if(fnQEmpty() == 1){
        return -1;
    }

    else if (front>rear){
        front = rear = -1;
        return -1;
    }
    
    else{
        data = arrQueue[front];
        front = front+1; 
        return data;
    }
}

void QDisplay(int arrQueue[]){
    int counter;
    if(fnQEmpty() == 1){
        printf("Nothing to Display.\n");
    }
    else if (front>rear)
    {
        printf("Nothing to Display.\n");
    }
    else{
        for(counter = front; counter<=rear; counter++){
            printf("%d\n", arrQueue[counter]);
        }
    }
}

int fnQFull(){
    if(rear == MAXSIZE-1)
        return 1;
    else 
        return 0;
}

int fnQEmpty(){
    if(front == -1 && rear == -1)
        return 1;
    else 
        return 0;
}

int main() { 

    int arrQueue[30], choice,data;

    do
    {
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");

        printf("Enter Your Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the Element : ");
            scanf("%d", &data);
            QInsertion(arrQueue, data);
            break;
        
        case 2:
            data = QDeletion(arrQueue);
            if (data == -1){
                printf("Queue is Empty\n");

            }
            else{
                printf("Item Delete = %d\n", data);
            }
            break;

        case 3:
            QDisplay(arrQueue);
            break;

        case 4:
            exit(1);

        default:
                printf("Wrong Choice: please see the options");
        }


    } while (1);
    

    return 0;
}