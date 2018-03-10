#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void menu();
double pertambahan(double num1,double num2);
double pengurangan(double num1,double num2);
double perkalian(double num1,double num2);
double pembagian(double num1,double num2);
int modulus(double num1,double num2);
void clear_buffer();
void calc(int choice);
double input();
void reset();


int main(){
    printf("Selamat datang di program kalkulator!");
    menu();
    return 0;
}

void menu(){
    double choice;
    int check;
    char buff;
    printf("\n\nPilih operasi:\n1.Pertambahan\n2.Pengurangan\n3.Perkalian\n4.Pembagian\n5.Modulus\n6.Exit\n\nPilihan : ");
    choice = input();
    check = ceil(choice);
    if (check == choice){
        if (choice>5 || choice < 1){
            if (choice == 6){
                    return;
            } else {
                system("cls");
                printf("Input invalid !");
                menu();
            }
        } else {
            calc(choice);
            reset();
        }
    }
    else {
        system("cls");
        printf("Input invalid!");
        menu();
    }
}

void calc(int choice){
    double num1;
    double num2;
    double sum;
    printf("Masukkan angka pertama : ");
    num1 = input();
    printf("Masukkan angka kedua : ");
    num2 = input();
    if(choice == 4 && num2 == 0){
        printf("Error,cannot divide by zero \n");
    } else {
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
                    sum = pembagian(num1,num2);
                    break;
                case 5:
                    sum = modulus(num1,num2);
                    break;
            }
        printf("Hasil Perhitungan : %.4lf",sum);
    }
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

double pembagian(double num1,double num2){
    return num1/num2;
}

int modulus(double num1,double num2){
    return (int)num1%(int)num2;
}

double input(){
    double num;
    char chara;
    if (scanf("%lf%c",&num,&chara)!= 2 && chara != '\n'){
        clear_buffer();
        system("cls");
        printf("Input invalid!\nMasukkan angka : ");
        return input();
    } else {
        return num;
    }
}

void clear_buffer(){
    char c;
    while ((c = getchar()) != '\n' && c != EOF) ; 
    
}

void reset(){

    int valid_reset;
    char parameter[1];

    printf("Kembali menghitung?[Y/N] ");
    gets(parameter);
    
    if (!(strcmp(parameter,"Y")) || !(strcmp(parameter,"y"))){
        
        system("cls");
        menu();

    } else if (!(strcmp(parameter,"N")) || !(strcmp(parameter,"n"))){
        
        return;

    } else {
        system("cls");
        printf("Invalid Input !\n\a");
        reset();
    }
}