#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{
    int id;
    char t[4];
}P;

int main(){
char m[100];

printf("Enter the message:");
fgets(m,sizeof(m),stdin);
m[strcspn(m,"\n")]='\0';

int n=(strlen(m)+2)/3;

P *p=(P*)malloc(n*sizeof(P));

for(int i=0;i<n;i++){
    p[i]=(P){i+1,""};
    memcpy(p[i].t,m+i*3,3);
}

printf("Pno. Data\n");
for(int i=0;i<n;i++){
    printf("%d:%s\n",p[i].id,p[i].t);
}

srand(time(0));
for(int i=n-1;i>0;i--){
    int j=rand()% i+1;
    P temp=p[i];
    p[i]=p[j];
    p[j]=temp;
}

printf("Packets recieved order:");
for(int i=0;i<n;i++){
    printf("%d ",p[i].id);
}

printf("\nPackets in order:");
for(int i=1;i<=n;i++){
    printf("%d ",i);
}

for (int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
        if(p[i].id>p[j].id){
            P temp=p[i];
            p[i]=p[j];
            p[j]=temp;
        }
    }
}

printf("\nMessage recieved:");
for(int i=0;i<n;i++){
    printf("%s",p[i].t);
}

    return 0;
}

//Output
// Enter the message:I love you
// Pno. Data
// 1:I l
// 2:ove
// 3: yo
// 4:u
// Packets recieved order:1        4       3       2
// Packets in order:1      2       3       4
// Message recieved:I love you




























