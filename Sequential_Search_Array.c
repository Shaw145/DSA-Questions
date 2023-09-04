

#include<stdio.h>
int fnsequential_search(int arrData[],int item,int n)
{
	for(int i=0;i<=n-1;i++)
	{
		if(arrData[i]==item)
		{
			return i;
			break;
		}
	}
	return -1;
}
int main()
{
	int i,arr[50],item,position,n;
	printf("enter the no of elements:");
	scanf("%d",&n);
	printf("enter the elements one by one:\n");
	for(i=0;i<n;i++)
	{
	  printf("enter arr[%d]",i);
	  scanf("%d",&arr[i]);
    }	
	printf("enter the element to be searched:");
	scanf("%d",&item);
	position=fnsequential_search(arr,item,n);
	if(position==-1)
	printf("element is not found\n");
	else
	printf("element is present at %d position\n",position);
	return 0;
}