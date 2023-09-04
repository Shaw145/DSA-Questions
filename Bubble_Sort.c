

#include<stdio.h>
#define TRUE 1
#define FALSE 0
void fnBubbleSort(int p[],int n)
{
	// int swap,iteration,j,temp;
	// swap=TRUE;
	// for(iteration=1;iteration<n&&swap==TRUE;iteration++)
	// {
	// 	swap=FALSE;
	// 	for(j=0;j<n-iteration;j++)
	// 	{
	// 		if(p[j]>p[j+1])
	// 		{
	// 		   swap=TRUE;
	// 		   temp=p[j];
	// 		   p[j]=p[j+1];
	// 		   p[j+1]=temp;	
	// 		}
	// 	}
	// }

	//Method - 1:
	for (int i = 0; i < n-1; i++)
	{
		int flag = 0;
		for (int j = 0; j < n-1-i; j++)
		{
			if(p[j]>p[j+1]){
				int temp = p[j];
				p[j]= p[j+1];
				p[j+1]=temp;
				flag = 1;
			}
		}
		if(flag == 0)
		break;	
	}

	// Method - 2:
	// for (int i = 0; i < n-1; i++)
	// {
	// 	for (int j = 0; j < n-1-i; j++)
	// 	{
	// 		if(p[j]>p[j+1]){
	// 			int temp = p[j];
	// 			p[j]= p[j+1];
	// 			p[j+1]=temp;
				
	// 		}
	// 	}
	// }
	
}
int main(void)
{
	int i,p[50],n;
	printf("enter the no of elements:");
	scanf("%d",&n);
	printf("enter the elements one by one:\n");
	for(i=0;i<n;i++)
	{
	  printf("enter p[%d]",i);
	  scanf("%d",&p[i]);
    }
    fnBubbleSort(p,n);
    printf("after sorting:\n");
    for(i=0;i<n;i++)
    printf("%d\t",p[i]);
    return 0;
}