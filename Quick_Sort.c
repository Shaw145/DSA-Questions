
#include<stdio.h>
int partition(int a[],int p,int r)
{
	int j;
	int pivot=a[r];
	int i=(p-1);
	for(j=p;j<=r-1;j++)
	{
		if(a[j]<=pivot)
		{
			i++;
			int t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	}
	int t=a[i+1];
	a[i+1]=a[r];
	a[r]=t;
	return (i+1);
}
void quick(int a[],int p,int r)
{
	if(p<r)
	{
		int n=partition(a,p,r);
		quick(a,p,n-1);
		quick(a,n+1,r);
	}
}
int main()
{
    int i,a[50],n;
	printf("enter the no of elements:");
	scanf("%d",&n);
	printf("enter the elements one by one:\n");
	for(i=0;i<n;i++)
	{
	  printf("enter a[%d]",i);
	  scanf("%d",&a[i]);
    }
    
    quick(a,0,n-1);
    printf("after sorting array elements are:\n");
    for(i=0;i<n;i++)
    printf("%d\t",a[i]);
    return 0;
}