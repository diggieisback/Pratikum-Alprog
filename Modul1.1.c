#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


void menu(bool isFirst,double lastSum);
void calc(bool isFirst,int choice,double lastSum);
double pertambahan(double num1,double num2);
double pengurangan(double num1,double num2);
double perkalian(double num1,double num2);
double pembagian(double num1,double num2,double lastSum);
int modulus(double num1,double num2);
void clear_buffer();
double input();


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
        num1 = input();
        printf("Masukkan angka kedua : ");
        num2 = input();
    }
    else {
        num1 = lastSum;
        printf("Hasil terakhir : %.2lf\n",num1);
        printf("Masukkan angka kedua : ");
        num2 = input();
    }
    isFirst = false;
    switch(choice){
        case 1 :
            sum = pertambahan(num1,num2);
            break;
        case 2 :
            sum = pengurangan(num1,num2);
            break;
        case 3:
            sum = perkalian(num1,num2);
            break;
        case 4:
            sum = pembagian(num1,num2,lastSum);
            break;
        case 5:
            sum = modulus(num1,num2);
            break;
    }
    system("cls");
    if(choice == 4 && num2 == 0){
        printf("Error,cannot divide by zero \n");
    }
    printf("Hasil operasi terakhir:%.4lf",sum);
    menu(isFirst,sum);
}

double pertambahan(double num1,double num2){
    return num1 + num2;
}

double pengurangan(double num1,double num2){
    return num1-num2;
}

double perkalian(double num1,double num2){
    return num1*num2;
}

double pembagian(double num1,double num2,double lastSum){
    if (num2 == 0){
        return lastSum;
    } else {
    return num1/num2;
    }
}

int modulus(double num1,double num2){
    return (int)num1%(int)num2;
}

double input(){
    double num;
    bool valid = scanf("%lf",&num);
    clear_buffer();
    if (valid == 0){
        printf("Input invalid! Masukkan angka : ");
        return input();
    } else {
        return num;
    }
}


void clear_buffer(){
    char c;
    while ((c = getchar()) != '\n' && c != EOF) ; 
    
}