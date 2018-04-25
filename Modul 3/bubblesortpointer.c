#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>


void bubbleSort(int arr[], int n);
void bubbleSortPointer(int *arr, int n);
float countBubbleSort(int arr[],int n);
float countBubbleSortPointer(int arr[],int n);
void menu();
void seedArray(int arr[],int n);
void menu2(int arr[],int n);
double input();
void clear_buffer();
void reset();
void printArray(int arr[], int n);

int main(){
    menu();
    return 0;
}

void bubbleSort(int arr[], int n){
    int i, j,temp;
    for (i = 0; i < n-1; i++)      
         for (j = 0; j < n-i-1; j++) 
            if (arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
    }
}

void bubbleSortPointer(int *arr, int n){
    int i,j,temp;
    for(i = 0;i <n - 1; i++)
        for(j = 0; j <n-i-1 ; j++)
            if(*(arr+j)>*(arr+j+1)){
                temp = *(arr+j);
                *(arr+j) = *(arr+j+1);
                *(arr+j+1) = temp;
            }
}

float countBubbleSort(int arr[],int n){
    clock_t start = clock();
    bubbleSort(arr,n);
    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;
    printf("Hasil Sorting :");
    printArray(arr,n);
    return seconds;
}

float countBubbleSortPointer(int arr[],int n){
    clock_t start = clock();
    bubbleSortPointer(arr,n);
    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;
    printf("Hasil Sorting :");
    printArray(arr,n);
    return seconds;
}

void menu(){

    float choice;
    int check;
    int n;
    printf("Pilih banyak data :\n\n1.1000\n2.16000\n3.64000\n4.Exit Program\n\nPilihan : ");
    choice = input();
    check = ceil(choice);
    if (check == choice){
        if (choice>3 || choice < 1){
                if (choice == 4){
                        return;
                } else {
                    system("cls");
                    printf("Input invalid !\n");
                    menu();
                }
        } else {
            switch ((int)choice)
            {
                case 1: 
                    n = 1000;
                    break;
                case 2: ;
                    n = 16000;
                    break;
                case 3: ;
                    n = 64000;
                    break;
            }
        }
        int arr[n];
        seedArray(arr,n);
        menu2(arr,n);
    } else {

        system("cls");

        printf("Input invalid!\n");

        menu();

    }

}

void seedArray(int arr[],int n){
    srand(0);
    for (int i = 0; i < n ; i++)
        arr[i] = rand();
}

void menu2(int arr[],int n){
        
    float choice;
    int check;
    float seconds;
    int angka;

    printf("Pilih metode yang diuji :\n\n1.Bubble Sort biasa\n2.Bubble Sort dengan pointer\n3.Exit Program\n\nPilihan :");
    choice = input();
    check = ceil(choice);
    if (check == choice){
        if (choice>2 || choice < 1){
                if (choice == 3){
                        return;
                } else {
                    system("cls");
                    printf("Input invalid !\n");
                    menu();
                }
        } else {
            switch ((int)choice)
            {
                case 1:
                    seconds = countBubbleSort(arr,n);
                    break;
                case 2:
                    seconds = countBubbleSortPointer(arr,n);
            }
        }
        printf("\nWaktu yang diperlukan : %lf",seconds);
        reset();
    } else {

        system("cls");

        printf("Input invalid!\n");

        menu();

    }
}

double input(){

    double num;
    char chara;
    if (scanf("%lf%c",&num,&chara)!= 2 || num<=0 || chara != '\n' || chara == ','){
        clear_buffer();
        printf("Input invalid! Masukkan angka yang benar : ");
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



    printf("\n\nKembali menghitung?[Y/N] ");

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

void printArray(int arr[], int n){
   int i;
   for (i=0; i < n; i++)
       printf("%d ", arr[i]);
   printf("\n");
}