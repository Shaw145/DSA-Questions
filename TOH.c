// Tower of Hanoi Using Recursion.....

# include<stdio.h>
# include<math.h>

void TOH(int, char, char, char);

int main() { 

    int n;

    printf("Enter the No of Disk : ");
    scanf("%d", &n);

    int total = pow(2,n)-1;

    printf("The no of Step Requried is : %d\n", total);

    TOH(n, 'A', 'B', 'C');
    

    return 0;
}

void TOH(int n,char A,char B,char C){

    if(n >1){
        TOH(n-1, A, C, B);
        printf("Moving disk %d from Tower %c to Tower %c\n", n,A,C);
        TOH(n-1, B, A , C);
    }
    else printf("Moving disk %d from Tower %c to Tower %c\n", n,A,C);

    // TOH(n-1, A, C, B);
    // printf("Moving disk %d from Tower %c to Tower %c\n", n,A,C);
    // TOH(n-1, B, A , C);
}
