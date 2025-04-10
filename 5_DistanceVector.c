#include <stdio.h>
#define INF 999

struct node{
    int dist[20];
    int from[20];
}rt[10];

int main(){
    int n, d[20][20];

    printf("Enter the no. of nodes:");
    scanf("%d",&n);

    printf("\nEnter the Cost matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&d[i][j]);
            rt[i].dist[j]=d[i][j];
            rt[i].from[j]=j;
        }
    }

    int change;
    do{
        change=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                 if(rt[i].dist[j]>d[i][k]+rt[k].dist[j]){
                    rt[i].dist[j]=d[i][k]+rt[k].dist[j];
                    rt[i].from[j]=k;
                    change=1;
                 }
                }
            }
        }
    }while(change);

    for(int i=0;i<n;i++){
        printf("Router:%d\nDist\tVia\tDest\n",i+1);
    
    for(int j=0;j<n;j++){
        printf("%d\t%d\t%d\n",j+1,rt[i].from[j]+1,rt[i].dist[j]);
    }}
    return 0;
}


//Output

// Enter the no. of nodes:3

// Enter the Cost matrix:
// 0 1 999
// 1 0 1
// 999 1 0
// Router:1
// Dist    Via     Dest
// 1       1       0
// 2       2       1
// 3       2       2
// Router:2
// Dist    Via     Dest
// 1       1       1
// 2       2       0
// 3       3       1
// Router:3
// Dist    Via     Dest
// 1       2       2
// 2       2       1
// 3       3       0