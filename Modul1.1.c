#include <stdio.h>

void menu();
void calc(int choice);
double pertambahan(int num1,int num2);

int main(){
    printf("Selamat datang di program kalkulator!");
    menu();
    return 0;
}

void menu(){
    int choice;
    printf("\n\nPilih operasi:\n1.Pertambahan\n2.Pengurangan\n3.Perkalian\n4.Pembagian\n5.Modulus\n\nPilihan : ");
    scanf("%d",choice);
    calc(choice);
}

void calc(int choice){
    double num1;
    double num2;
    double sum;
    printf("Masukkan angka pertama : ");
    scanf("%lf",num1);
    printf("Masukkan angka kedua : ");
    scanf("%lf",num2);
    switch(choice){
        case 1 :
            sum = pertambahan(num1,num2);
            break;
    }
    printf("%d",sum);
}

double pertambahan(int num1,int num2){
    return num1 + num2;
}
