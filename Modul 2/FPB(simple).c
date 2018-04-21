#include <stdio.h>

int FPBIter(int num1,int num2);
int FPBRecur(int num1,int num2);
void menu();

int main(){
    menu();
    return 0;
}

void menu(){
    int num1,num2,temp,sum;
    scanf("%d %d",&num1,&num2);
     if(num1 < num2){
        temp = num2;
        num2 = num1;
        num1 = temp;
    }
    sum = FPBIter(num1,num2);
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
            break;
        }
    }
    return sum;
}