#include <stdio.h>
#include <string.h>

int main(){
char data[50],gen[50],code[50],rem[50],recv[50];
int e,pos;
printf("Enter the data and Generator:");
scanf("%s%s",data,gen);

int dlen=strlen(data);
int glen=strlen(gen);

sprintf(code,"%s%0*d",data,glen-1,0);

printf("Modified data:%s",code);

strncpy(rem,code,glen);

for(int i=0;i<=strlen(code)-glen;i++){
    if(rem[0]==1)
        for(int j=0;j<glen;j++)
            rem[j]=(rem[j]==gen[j])?0:1;
        
    memmove(rem,rem+1,glen-1);
    rem[glen-1]=code[i+glen];
}
rem[glen-1]='\0';

strcpy(code+dlen,rem);
strcpy(recv,code);

printf("CRC value: %s\n", rem);
    printf("Final data sent: %s\n", code);

    printf("Enter 1 if there's an error needed to be transmitted, 0 otherwise: ");
    scanf("%d", &e);
    if (e == 1)
    {
        printf("Enter error position : ");
        scanf("%d", &pos);
        recv[pos-1] ^= 1;
    }
    printf("Data recieved through transmission: %s\n", recv);




    return 0;
}


//Example
//Enter Data and Generator: 1101011011 10011
//Modified Data padded with n-1 zero: 11010110110000
//CRC value: 1110
//Final data sent: 11010110111110
//Enter 1 if there's an error needed to be transmitted, 0 otherwise: 1
//Enter error position : 3
//Data recieved through transmission: 11110110111110

//Enter Data and Generator: 1101011011 10011
//Modified Data padded with n-1 zero: 11010110110000
//CRC value: 1110
//Final data sent: 11010110111110
//Enter 1 if there's an error needed to be transmitted, 0 otherwise: 0
//Data recieved through transmission: 11010110111110






