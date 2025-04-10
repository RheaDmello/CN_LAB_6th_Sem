#include <stdio.h>

struct packet{
    int time;
    int size;
}p[50];

int main(){
    int i,n,m,k=0;
    int bsize,bfilled,outrate;

    printf("Enter the no. of packets:");
    scanf("%d",&n);

    printf("Enter the packets in packet arrival time:\n");

    for(i=0;i<n;i++){
        printf("Enter the time and size:");
        scanf("%d%d",&p[i].time,&p[i].size);
    }
    printf("Enter the bucket size:");
    scanf("%d",&bsize);
    printf("Enter the output rate:");
    scanf("%d",&outrate);

    m=p[n-1].time;
    i=1;
    k=0;
    bfilled=0;

    while(i<=m || bfilled!=0){
        printf("\n\nAt Time %d\n",i);

        if(p[k].time==i){
            if(bsize>=bfilled+p[k].size){
                bfilled=bfilled+p[k].size;
                printf("\n %d byte packets inserted",p[k].size);
                k+=1;
            }
            else{
                printf("\n %d byte packets discarded",p[k].size);
                k+=1;
            }
        }

        if (bfilled==0){
            printf("\n No packets to transmit");
        }

        else if(bfilled>=outrate){
            bfilled=bfilled-outrate;
            printf("\n %d byte packets transferred",outrate);
        }

        else{
            printf("\n %d byte packets transferred",bfilled);
            bfilled=0;
        }
        
        printf("\n Packets in bucket %d byte",bfilled);
        i++;
    }
    return 0;
}

