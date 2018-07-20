#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include<math.h>

int BinaryToDec(int n)
{
    int r,dec=0,j=0;
    /*printf("\nEnter binary no:");
     scanf("%d",&n);*/
    //printf("%d",n);
    while(n!=0){
        r=n%10;
        n=n/10;
        dec=dec+(r  * pow(2,j));
        j++;
    }
    //        printf("%d",dec);
    return dec;
    
    
    
}
int OctalToDec(int n)
{
    int r,dec=0,j=0;
    /*printf("\nEnter Octal no:");
     scanf("%d",&n);*/
    //printf("%d",n);
    while(n!=0){
        r=n%10;
        n=n/10;
        dec=dec+(r  * pow(8,j));
        j++;
    }
    //        printf("%d",dec);
    return dec;
    
    
    
}

int HexaToDec(char a[]){
    printf("%s sbhs",a);
    int len , j,i,decimal=0,x=1;
    /*printf("Enter the Hexadecimal:");
     fgets(a,sizeof(a),stdin);*/
    len = strlen(a);
    for(i=len-2;i>=0;i--){
        if(isalpha(a[i])){
            if(a[i]=='A'){
                decimal=decimal+10*x;
            }
            if(a[i]=='B'){
                decimal=decimal+11*x;
            }
            if(a[i]=='C'){
                decimal=decimal+12*x;
            }
            if(a[i]=='D'){
                decimal=decimal+13*x;
            }
            if(a[i]=='E'){
                decimal=decimal+14*x;
            }
            if(a[i]=='F'){
                decimal=decimal+15*x;
            }
        }
        else{
            j=a[i]-'0';
            decimal=decimal+j*x;
        }
        x=x*16;
    }
    return decimal;
}
int DecimalToBinary(int n)
{
    int  i=1,rem,binary=0;
    /*printf("\nenter decimal no:");
     scanf("%d",&n);*/
    while(n!=0){
        rem=n%2;
        binary=binary+(rem*i);
        i=i*10;
        n=n/2;
    }
    return binary;
    
}
int DecimalToOctal(int n)
{
    int  i=1,rem,octal=0;
    /*printf("\nenter decimal no:");
     scanf("%d",&n);*/
    while(n!=0){
        rem=n%8;
        octal=octal+(rem*i);
        i=i*10;
        n=n/8;
    }
    return octal;
    
}
char* DecimalToHexa(int n){
    int rem,i=0;
    char* hexD = (char*)malloc((20) * sizeof(char));
    //char* t2 = (char*)malloc((length+1) * sizeof(char));
    /*printf("Enter decimal:");
     scanf("%d",&n);*/
    while(n!=0){
        rem=n%16;
        if(rem<10){
            hexD[i]= rem+48;
            i++;
        }
        else{
            hexD[i] = rem+55;
            i++;
        }
        n=n/16;
    }
    hexD[i]='\0';
    //printf("hol%c",hexD[0]);
    // strrev(hexD);
    char temp;
    int last = i;
    //printf("hfh %c",hexD[1]);
    for(int j=0;j<i/2;j++)
    {
        temp = hexD[i];
        hexD[i] = hexD[last-1];
        hexD[last-1]=temp;
        last--;
    }
    //printf("%s",hexD);
    
    return hexD;
}
int BinaryToOct(int binary){
    int dec,oct;
    dec = BinaryToDec(binary);
    oct=DecimalToOctal(dec);
    return oct;
}
int OctToBinary(int binary){
    int dec,oct;
    dec = OctalToDec(binary);
    oct=DecimalToBinary(dec);
    return oct;
}

int main()
{
    int dec , decNo,choice ;
    char* hexNo ;
    char a[20];
    printf("1.DecimalToBinary\n2.DecimalToOctal\n3.DecimalToHexa\n4.BinaryToDec\n5.OctalToDec\n6.HexaToDec\n7.BinaryToOct\n8.OctToBinary");
    printf("\nEnter choice:");
    scanf("%d",&choice);
    if(choice==1){
        printf("Enter decimal:");
        scanf("%d",&decNo);
        dec=DecimalToBinary(decNo);
        printf("%d",dec);
        
    }
    if(choice==2){
        printf("Enter decimal:");
        scanf("%d",&decNo);
        dec=DecimalToOctal(decNo);
        printf("%d",dec);
        
    }
    if(choice==3){
        printf("Enter decimal:");
        scanf("%d",&decNo);
        hexNo=DecimalToHexa(decNo);
        printf(" %s",hexNo);
        
    }
    if(choice==4)
    {
        printf("Enter Binary:");
        scanf("%d",&decNo);
        dec=BinaryToDec(decNo);
        printf("%d",dec);
    }
    if(choice==5)
    {
        printf("Enter octal:");
        scanf("%d",&decNo);
        dec=OctalToDec(decNo);
        printf("%d",dec);
    }
    if(choice==6){
        printf("Enter the Hexadecimal:");
        fgets(a,sizeof(a),stdin);
        dec = HexaToDec(a);
        printf("%d",dec);
    }
    if(choice==7)
    {
        printf("Enter Binary:");
        scanf("%d",&decNo);
        dec=BinaryToOct(decNo);
        printf("%d",dec);
    }
    if(choice==8)
    {
        printf("Enter Octal:");
        scanf("%d",&decNo);
        dec=OctToBinary(decNo);
        printf("%d",dec);
    }
    return 0;
}
