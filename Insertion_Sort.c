
#include<stdio.h>
 
void fnInsertionSort(int p[],int n)
{
	int iteration,j,temp;
	for(iteration=1;iteration<n;iteration++)
	{
		temp=p[iteration];
		for(j=iteration-1;j>=0 && temp<p[j];j--)
		p[j+1]=p[j];
		p[j+1]=temp;
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
    fnInsertionSort(p,n);
    printf("after sorting:\n");
    for(i=0;i<n;i++)
    printf("%d\t",p[i]);
    return 0;
}