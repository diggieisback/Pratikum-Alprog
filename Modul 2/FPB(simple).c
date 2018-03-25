#include <stdio.h>

int FPBIter(int num1,int num2);
int FPBRecur(int num1,int num2);
void menu();

int main(){
    menu();
    return 0;
}

void menu(){
    int num1,num2,temp,sum,choice;
    printf("Pilih menu :\n1.FPB Iteratfi\n2.FPB Rekursif\n\nPilihan : ");
    scanf("%d",&choice);
    printf("Input angka 1 : ");
    scanf("%d",&num1);
    printf("Input angka 2 : ");
    scanf("%d",&num1);
    if(num1 < num2){
        temp = num2;
        num2 = num1;
        num1 = temp;
    }
    switch(choice){
        case 1:
            sum = FPBIter(num1,num2);
            break;
        case 2 :
            sum = FPBRecur(num1,num2);
    }
    printf("%d",sum);
}

int FPBIter(int num1,int num2){
    int sum = 1;
    int temp;
    for(int i = 2;i<=num1;i++){
        if(num1 % i == 0 && num2 % i == 0){
            sum = i;
        }
    }
    return sum;
}

int FPBRecur(int num1,int num2){
    int sum = 1;
    for(int i = 2; i<num1 ; i++){
        if(num1 % i == 0 && num2 % i == 0){
            sum = i * FPBRecur(num1/i,num2/i);
            printf("%d",sum);
            break;
        }
    }
    return sum;
}