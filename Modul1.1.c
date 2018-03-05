#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void menu(bool isFirst,double lastSum);
void calc(bool isFirst,int choice,double lastSum);
double pertambahan(int num1,int num2);

int main(){
    bool isFirst = true;
    printf("Selamat datang di program kalkulator!");
    menu(isFirst,0);
    return 0;
}

void menu(bool isFirst,double lastSum){
    int choice;
    printf("\n\nPilih operasi:\n1.Pertambahan\n2.Pengurangan\n3.Perkalian\n4.Pembagian\n5.Modulus\n6.Exit\n\nPilihan : ");
    scanf("%d",&choice);
    calc(isFirst,choice,lastSum);
}

void calc(bool isFirst,int choice,double lastSum){
    double num1;
    double num2;
    double sum;
    if (choice == 6){
        return;
    }
    else if (isFirst){
        printf("Masukkan angka pertama : ");
        scanf("%lf",&num1);
        printf("Masukkan angka kedua : ");
        scanf("%lf",&num2);
    }
    else {
        num1 = lastSum;
        printf("Masukkan angka kedua : ");
        scanf("%lf",&num2);
    }
    isFirst = false;
    switch(choice){
        case 1 :
            sum = pertambahan(num1,num2);
            break;
        case 2 :
            sum = pengurangan(num1,num2);
    }
    system("cls");
    printf("Hasil operasi :%lf",sum);
    menu(isFirst,sum);
}

double pertambahan(int num1,int num2){
    return num1 + num2;
}
