

#include<stdio.h>
int fnBinarySearch_Recursive(int arrData[],int low,int high,int item)
{
	if(low>high)
	{
		return -1;
	}
	else
	{
		int mid=(low+high)/2;
		if(item==arrData[mid])
		return mid;
		else if(item<arrData[mid])
		fnBinarySearch_Recursive(arrData,low,mid-1,item);
		else
		fnBinarySearch_Recursive(arrData,mid+1,high,item);
	}
}
int main(void)
{
	int i,arr[50],item,result,n;
	printf("enter the no of elements:");
	scanf("%d",&n);
	printf("enter the elements one by one:\n");
	for(i=0;i<n;i++)
	{
	  printf("enter a[%d]",i);
	  scanf("%d",&arr[i]);
    }	
	printf("enter the element to be searched:");
	scanf("%d",&item);
	result=fnBinarySearch_Recursive(arr,0,n-1,item);
	if(result==-1)
	printf("element is not found\n");
	else
	printf("element is present at %d position\n",result);
	return 0;
}