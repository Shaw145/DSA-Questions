
# include<stdio.h>
#define TRUE 1
#define FALSE 0
#define INFINITY 9999
#define MAX 10

int n,s;

int minimum(int dist[MAX], int visited[MAX]){

    int v;
    int min = INFINITY;
    for(int i =1; i<=n; i++){

        if(visited[i] == FALSE && dist[i]< min){
            v = i;
            min = dist[i];
        }
    }
    return v;
}

void dijkstra(int n, int s, int cost[MAX][MAX]){

    int prev[MAX],dist[MAX],visited[MAX];

    for(int i = 1; i<=n; i++){
        dist[i] = INFINITY;
        visited[i] = FALSE;
    }
    dist[s] = 0;
    prev[s] = -1;

    for(int i=0; i<n-1; i++){

        int u = minimum(dist,visited);
        visited[u] = TRUE;

        for(int j =1; j<=n;j++){

            if(cost[u][j] != 0 && visited[j] == FALSE && dist[u] != INFINITY && (dist[u]+cost[u][j]<dist[j])){
                dist[j] = dist[u] + cost[u][j];
                prev[j] = u;
            }

        }

    }

    for(int i =1; i<=n;i++){

        if(i!=s){
            printf("\n\nDistance between %d to %d = %d\n", s, i, dist[i]);

            printf("Path = %d",i);
			int j=i;
			do{
				j=prev[j];
				printf("<-%d",j);
			}while(j!=s);
                
        }

    }

}

int main() { 

    printf("\n\nEnter No of Vertices : ");
	scanf("%d",&n);

    int cost[MAX][MAX];

    printf("\nEnter the Cost Matrix : \n");
    for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			scanf("%d", &cost[i][j]);
    }

    printf("\nEnter the Starting Node : ");
	scanf("%d",&s);

    dijkstra(n,s,cost);

    return 0;
}


/*
Sample Input 1:

0 1 4 0 0 0
1 0 4 2 7 0
4 4 0 3 5 0
0 2 3 0 4 6
0 7 5 4 0 7
0 0 0 6 7 0

Start = 1

Output:
0   1   4   3   7   9
----------------------------------
Sample Input 2 :

0 1 1 1
1 0 1 0
1 1 0 1
1 0 1 0

Start = 2

Ouput:
1   0   1   2

----------------------------
Sample Input 3 :

0 2 3 0 0 0 0
2 0 5 7 9 0 0
3 5 0 4 0 0 0
0 7 4 0 2 2 3
0 9 0 2 0 5 0
0 0 0 2 5 0 3
0 0 0 3 0 3 0

start = 1

output:
0   2   3   7   9   9   10

*/

