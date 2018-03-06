#include <stdio.h>
#include <math.h>

void menu();
void binaryToDecimal();
void decimalToBinary();

int main(){
    printf("Selamat datang di program konversi biner desimal");
    menu();
    return 0;
}

void menu(){
    int choice;
    printf("Mauskann pilihan\n\n1.Biner ke desimal\n2.Desimal ke biner\n\nPilihan :");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            binaryToDecimal();
            break;
    //     case 2 :
    //         decimalToBinary();
    //         break;
    }
}

void binaryToDecimal(){
    int angka;
    int sum = 0;
    int count=0;
    printf("Masukkan angka biner : ");
    scanf("%d",&angka);
    int sumDiv = angka;
    int sumMod = angka;
    if(angka != 0 && angka != 1){
        do {
            sumDiv = sumDiv / 10;
            sumMod = sumMod % 10;
            if (sumMod == 1){
                sum = sum + pow(2,count);
            }
            count ++;
        } while(sumDiv != 0);
    } else {
        sum = angka;
    }
    printf("%d",sum);
}

void decimalToBinary(){
    int angka;
    int sum = 0;
    int count = 0;
    int *array;
    array = malloc(sizeof(int)*10);
    printf("Masukkan angka decimal : ");
    scanf("%d",&angka);
    int sumDiv = angka;
    int sumMod = angka;
    if(angka != 0 && angka != 1){
        while(sumDiv != 0){
            sumDiv = sumDiv / 2;
            sumMod = sumDiv % 2;
            array[count] = sumMod;
            count ++;
        }
        int array[count];
    
    } else {
        sum = angka;
    }
    printf("%d",sum);
    free(array);
}