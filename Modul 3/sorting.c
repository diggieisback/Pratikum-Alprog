#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

void insertionSort(int arr[], int n);
void bubbleSort(int arr[], int n);
void quickSort(int arr[], int low, int high);
float countInsertionSort(int arr[], int n);
float countBubbleSort(int arr[], int n);
float countQuickSort(int arr[],int n);
float countSequentialSearch(int arr[],int n,int angka);
float countBinarySearch(int arr[],int n,int angka);
int sequentialSearch(int arr[],int n,int angka);
int binarySearch(int arr[],int low,int high, int angka);
int partition (int arr[], int low, int high);
void printArray(int arr[], int n);
void seedArray(int arr[],int n);
void menu();
void menu2(int arr[],int n);
void reset();
double input();
void dupArray(int source[],int target[], int n);
void clear_buffer();



int main(){
    menu();
    return 0;
}

void seedArray(int arr[],int n){
    srand(0);
    for (int i = 0; i < n ; i++)
        arr[i] = rand();
}

void insertionSort(int arr[], int n){
    int i, key, j;
    clock_t start = clock();
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i-1;

        
        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
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

int sequentialSearch(int arr[],int n,int angka){
    for(int i = 0; i < n ; i++){
        if(arr [i] == angka){
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[],int low,int high, int angka){
    bool inArray;
    if (high >= low)
    {
        int mid = low + (high - low)/2;
 
        if (arr[mid] == angka)  
            return mid;

        if (arr[mid] > angka) 
            return binarySearch(arr, low, mid-1, angka);
 
        return binarySearch(arr, mid+1, high, angka);
   }
 
   return -1;
}

float countBinarySearch(int arr[],int n,int angka){
    int inArray;
    quickSort(arr,0,n-1);
    clock_t start = clock();
    inArray = binarySearch(arr,0,n-1,angka);
    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;
    if(inArray == -1){
        printf("Angka %d tidak terdapat di array",angka);  
    } else {
        printf("Angka %d berada di array di indeks ke %d",angka,inArray);    
    }
    return seconds;
}

int partition (int arr[], int low, int high){
    int pivot = arr[high];    
    int temp;
    int i = (low - 1);  
 
    for (int j = low; j <= high- 1; j++)
    {
        
        if (arr[j] <= pivot)
        {
            i++;    
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}
 
void quickSort(int arr[], int low, int high){
    if (low < high)
    {
        
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

float countBubbleSort(int arr[],int n){
    clock_t start = clock();
    bubbleSort(arr,n);
    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;
    return seconds;
}

float countInsertionSort(int arr[],int n){
    clock_t start = clock();
    insertionSort(arr,n);
    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;
    return seconds;
}

float countQuickSort(int arr[],int n){
    clock_t start = clock();
    quickSort(arr,0,n-1);
    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;
    return seconds;
}

float countSequentialSearch(int arr[],int n,int angka){
    int inArray;
    clock_t start = clock();
    inArray = sequentialSearch(arr,n,angka);
    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;
    if(inArray == -1){
        printf("Angka %d tidak terdapat di array",angka); 
    } else {
        printf("Angka %d berada di array di indeks ke %d",angka,inArray);    
    }
    return seconds;
}

void printArray(int arr[], int n){
   int i;
   for (i=0; i < n; i++)
       printf("%d ", arr[i]);
   printf("\n");
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
                    n = 100000;
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

void menu2(int arr[],int n){
        
    float choice;
    int check;
    float seconds1,seconds2,seconds3;
    int angka;
    int arr2[n];
    int arr3[n];
    printf("Pilih metode yang diuji :\n\n1.Sorting(Bubble Sort,Insertion Sort,Quick Sort)\n2.Searching(Binary Search,SequentialSearch)\n3.Exit Program\n\nPilihan :");
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
            printf("Array %d data random sebelum di sort :\n");
            printArray(arr,n);
            if(choice ==2){
                printf("Masukkan angka yang dicari : ");
                angka = input();
            }
            dupArray(arr,arr2,n);
            dupArray(arr,arr3,n);
            switch ((int)choice)
            {
                case 1:
                    seconds1 = countInsertionSort(arr,n);
                    seconds2 = countBubbleSort(arr2,n);
                    seconds3 = countQuickSort(arr3,n);
                    break;
                case 2:
                    seconds1 = countSequentialSearch(arr,n,angka);
                    seconds2 = countBinarySearch(arr2,n,angka);
                    break;
            }
        }
        printf("Array %d data random sesudah di sort :\n");
        printArray(arr2,n);
        if(choice == 1){
            printf("Waktu Quick Sort : %lf\nWaktu Insertion Sort : %lf\nWaktu Bubble Sort : %lf",seconds3,seconds1,seconds2);
        } else if(choice == 2) {
            printf("Waktu Sequential Search : %lf\nWaktu Binary Search :%lf",seconds1,seconds2);
        }
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

void dupArray(int source[],int target[], int n){
    for(int i = 0; i < n ; i++)
        target[i] = source[i];
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