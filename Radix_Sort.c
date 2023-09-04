
#include<stdio.h>

 
 void radix_sort(int n, int p[]){

 int bucket[10][5],buck[10],b[10];
 int i,j,k,l,num,div,large,passes;

 div=1;
 num=0;
 large=p[0];

 for(i=1;i<n;i++){

 if(p[i]>large)
 large=p[i];
}

 while(large>0){

 num++;
 large=large/10;
}

 for(passes=0;passes<num;passes++){

    for(k=0;k<10;k++)
        buck[k]=0;
    for(i=0;i<n;i++){
        j=(p[i]/div)%10;
        bucket[j][buck[j]++]=p[i];
    }

    i=0;

    for(k=0;k<10;k++){
        for(j=0;j<buck[k];j++)
            p[i++]=bucket[k][j];
    }

    div*=10;
    }
}

void main(){

    int n,i,p[100];
    
    printf("enter no of elemnts:");
    scanf("%d",&n);

    printf("enter the elements now : \n");
    for(i=0;i<=n-1;i++){
        scanf("%d",&p[i]);
    }
    radix_sort(n,p);

    printf("after sorting\n");

    for(i=0;i<=n-1;i++)
        printf("%d\t",p[i]);
}