
# include<stdio.h>
int total;

void TOH(char A, char B, char C, int N){
    if (N == 1)
    {
        printf("%c -> %c\n", A,C);
        total++;
        return;
    }
    else{
        TOH(A,C,B,N-1);
        TOH(A,B,C,1);
        TOH(B,A,C,N-1);
    }
    
}

int main() { 

    int n;
    printf("Enter the Number of Disks : ");
    scanf("%d", &n);

    total = 0;
    TOH('A', 'B', 'C', n);
    printf("Total Number of moves are %d\n\n", total);

    return 0;
}