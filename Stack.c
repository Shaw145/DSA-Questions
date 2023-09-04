
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 30

void fnPush(int[], int);
int fnPop(int[]);
void fnDisplay(int[]);
int fnFull();
int fnEmpty();
int top = -1;

void fnPush(int arrSTACK[], int data){
    if(fnFull() == 1){
        printf("Stack is Full\n");
    }
    else{
        top = top +1;
        arrSTACK[top] = data;
    }
}

int fnPop(int arrSTACK[]){
    int data;
    if(fnEmpty() == 1){
        return -1;
    }
    else{
        data = arrSTACK[top];
        top = top -1;
        return data;
    }
}

void fnDisplay(int arrSTACK[]){
    int counter;
    if (fnEmpty() == 1){
        printf("Nothing to Display\n");
    }
    else{
        for(counter = 0; counter<= top; counter++){
            printf("%d\n", arrSTACK[counter]);
        }
    }

}

int fnFull(){
    if(top == MAXSIZE-1){
        return 1;
    }
    else return 0;
}

int fnEmpty(){
    if(top == -1){
        return 1;
    }
    else return 0;
}

void main(){
    int arrSTACK[30], choice,data;

    do{
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
            fnPush(arrSTACK, data);
            break;

        case 2:
            data = fnPop(arrSTACK);
            if (data == -1){
                printf("Stack is Empty\n");

            }
            else{
                printf("Item Delete = %d\n", data);
            }
            break;

        case 3 :
            fnDisplay(arrSTACK);
            break;

        case 4:
            exit(1);
        
        
        }
    }while(1);
}