#include<stdio.h>
void fnMsort(int[],int,int);
void fnMerge(int[],int,int,int);
void fnMsort(int p[],int low,int high)
{
	int mid;
	if(low>=high)
	return;
		mid=(low+high)/2;
		fnMsort(p,low,mid);
		fnMsort(p,mid+1,high);
		fnMerge(p,low,mid,high);
	
}
void fnMerge(int p[],int low,int mid,int high)
{
	int h,k,j,b[50];
	h=low;
	k=low;
	j=mid+1;
	while(h<=mid && j<=high)
	{
		if(p[h]<=p[j])
		{
			b[k]=p[h];
			h=h+1;
		}
		else
		{
			b[k]=p[j];
			j=j+1;
		}
		k=k+1;
	}
	while(h<=mid)
	{
		b[k]=p[h];
		h=h+1;
		k=k+1;
	}
	while(j<=high)
	{
		b[k]=p[j];
		j=j+1;
		k=k+1;
	}
	for(k=low;k<=high;k++)
	p[k]=b[k];
}
int main(void)
{
	int n,p[50],i;
	printf("enter no of elements in the array\n");
	scanf("%d",&n);
	printf("enter the elements now\n");
	for(i=0;i<n;i++)
	scanf("%d",&p[i]);
	fnMsort(p,0,n-1);
	printf("after sorting:\n");
	for(i=0;i<n;i++)
	printf("%d\t",p[i]);
	printf("\n");
}