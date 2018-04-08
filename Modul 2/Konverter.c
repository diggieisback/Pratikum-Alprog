#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
void menu();
void binaryToDecimal();
void decimalToBinary();
void clear_buffer();

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
        case 2 :
            decimalToBinary();
            break;
    }
}

void binaryToDecimal(){
    
    int sum = 0;
    int n,x;
    printf("Masukkan panjang angka biner : ");
    scanf("%d",&n);
    int angka[n];
    int count = n-1;
    printf("Masukkan angka biner : ");
    for (int i = 0 ; i < n ; i++){
        scanf("%1d",&x);
        angka[i] = x;
    }
    for (int i = 0 ; i < n ; i ++ ){
        if (angka[i] == 1){
            sum = sum + pow(2,count);
        }
        count--;
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
    printf("Nilai biner : ");
    if (angka == 0 || angka == 1){
        printf("%d",angka);
    } else {
        int sumDiv = angka;
        int sumMod = angka;
        if(angka != 0 && angka != 1){
            while(sumDiv != 0){
                sumMod = sumDiv % 2;
                sumDiv = sumDiv / 2;
                array[count] = sumMod;
                count ++;
            }    
        } else {
            sum = angka;
        }
        for (int i = count-1; i >= 0; i--){
            printf("%d",array[i]);
        }
        free(array);
    }
}

void clear_buffer(){

    char c;

    while ((c = getchar()) != '\n' && c != EOF) ; 

    

}
