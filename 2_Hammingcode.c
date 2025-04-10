#include <stdio.h>

void generate(int data[4],int hc[7]){
    hc[6]=data[0];
    hc[5]=data[1];
    hc[4]=data[2];
    hc[2]=data[3];

    hc[0]=hc[2]^hc[4]^hc[6];
    hc[1]=hc[2]^hc[5]^hc[6];
    hc[3]=hc[4]^hc[5]^hc[6];

}

void detect(int r[7]){
    int p1,p2,p3,error=0;

    p1=r[0]^r[2]^r[4]^r[6];
    p2=r[1]^r[2]^r[5]^r[6];
    p3=r[3]^r[4]^r[5]^r[6];

    error=(p3<<2) | (p2<<1) | (p1<<0);

    if(error!=0){
        printf("Error detected at position %d\n",error);
        r[error-1]^=1;
        printf("Error detected ");
    }
    else{
        printf("no error");
    }

    printf("Corrected hamming code:\n");
    for(int i=6;i>=0;i--){
        printf("%d",r[i]);
    }

}

int main() { 
    int data[4], hammingCode[7], receivedCode[7]; 
 
    printf("Enter 4-bit data ( space-separated): "); 
    for (int i = 0; i < 4; i++) { 
        scanf("%d", &data[i]); 
    } 
 
   generate(data, hammingCode); 
    printf("Generated Hamming Code : "); 
    for (int i = 6; i >= 0; i--) { 
        printf("%d", hammingCode[i]); 
    } 
    printf("\n"); 
 
    printf("Enter received 7-bit Hamming Code ( space-separated):   "); 
    for (int i = 6; i >= 0; i--) { 
scanf("%d", &receivedCode[i]); 
} 
detect(receivedCode); 
return 0; 
} 

//Output

// Enter 4-bit data ( space-separated): 1 0 1 1
// Generated Hamming Code : 1010101
// Enter received 7-bit Hamming Code ( space-separated):   1 0 1 0 0 0 1
// Error detected at position 3
// Error detected Corrected hamming code:
// 1010101