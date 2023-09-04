
#include<stdio.h>
#define TRUE 1
#define FALSE 0
void fnSelectionSort(int p[],int n)
{
	int k,loc,j,temp;
	for(k=0;k<n-1;k++)
	{
		loc=k;
		for(j=k+1;j<n;j++)
			if(p[j]<p[loc])
			loc=j;
			if(loc!=k)
			{
			   temp=p[k];
			   p[k]=p[loc];
			   p[loc]=temp;	
			}
		
		
	}
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
    fnSelectionSort(p,n);
    printf("after sorting:\n");
    for(i=0;i<n;i++)
    printf("%d\t",p[i]);
    return 0;
}