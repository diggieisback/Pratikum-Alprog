#include <stdio>

int main(){

}

int FPB(int num1,int num2){
    sum = 1;
    if(num1 < num2){
        temp = num2;
        num2 = num1;
        num1 = temp;
    }
    for(int i = 2,i<=num1,i++){
        if(num1 % i == 0 && num2 % i == 0){
            sum = sum * i;
        }
    }

}