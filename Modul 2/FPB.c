#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct faktor{
    int* list;
    int count;
}Faktor;

Faktor determine(int num);
int FPB(Faktor faktor1,Faktor faktor2);

int main(){
    Faktor faktor1,faktor2;
    int num1,num2,my;
    faktor1.list = malloc(sizeof(int)*10);
    faktor2.list = malloc(sizeof(int));
    printf("Masukkan angka pertama : ");
    scanf("%d",&num1);
    printf("Masukkan angka kedua : ");
    scanf("%d",&num2);
    faktor1 = determine(num1);
    faktor2 = determine(num2);
    my = FPB(faktor1,faktor2);
    printf("%d",my);
    return 0;
}

Faktor determine(int num){
    Faktor myFactor;
    myFactor.list = malloc(sizeof(int)*10);
    myFactor.count = 0;
    for (int i = 1; i <= num ; i++){
        if(num % i == 0){
            myFactor.list[myFactor.count] = i;
            myFactor.count++;
        }
    }
    return myFactor;
}

int FPB(Faktor faktor1,Faktor faktor2){
    int FPB = 0;
    bool isFPB = false;
    for (int i = 0; i <faktor1.count; i++){
        for (int j = 0; j < faktor2.count; j++){
            if(faktor1.list[i] == faktor2.list[j]){
                FPB = faktor1.list[i];
                isFPB = true;
            }
        }
    }
    return FPB;
}