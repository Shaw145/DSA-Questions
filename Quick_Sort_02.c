
#include<stdio.h>

int fnPartition(int A[],int lb,int ub){

	int pivot = A[lb];
	int start = lb, end = ub;

	while (start<end){

		while(A[start]<= pivot){
			start++;
		}
		while(A[end]> pivot){
			end--;
		}
		if(start<end){
			int temp = A[start];
			A[start] = A[end];
			A[end] = temp;
		}
	}

	int temp = A[lb];
	A[lb] = A[end];
	A[end] = temp;
	
	return end;	
}

void fnQsort(int A[],int start,int end){

	if(start<end){
	
		int  j = fnPartition(A,start,end);
		fnQsort(A,start,j-1);
		fnQsort(A,j+1,end);

    }
}

int main(void)
{
	int n,P[50],i;

	printf("enter no of elements in the array : ");
	scanf("%d",&n);

	printf("enter the elements now\n");
	for(i=0;i<n;i++)
	scanf("%d",&P[i]);

	fnQsort(P,0,n-1);

	printf("after sorting:\n");
	for(i=0;i<n;i++)
	printf("%d\t",P[i]);
	printf("\n");
}