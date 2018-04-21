#include <stdio.h>

int fibonacci(int n);
void arrayRec(int n);
void arrayIter(int n);
void menu();

int main(){
    menu();
    return 0;
}

void menu(){
    int choice;
    int n;
    printf("Menu :\n1.Fibonacci iteratif\n2.Fibonacci rekursif\n3.Exit Program\n\nMasukkan pilihan : ");
    choice = input();
    printf("Masukkan panjang deret : ");
    n = input();
    switch(choice){
        case 1:
            arrayIter(n);
            break;
        case 2:
            arrayRec(n);
            break;
    }
}

int fibonacci(int n){   
    if (n == 0){
        return 0;
    } else if (n == 1){
        return 1;
    } else {
       return fibonacci(n-2) + fibonacci(n-1);
    }
}

void arrayRec(int n){
    int array[n];
    printf("%d deret bilangan fibonacci : ",n);
    for (int i = 0;i < n; i++){
        array[i] = fibonacci(i);
        printf("%d ",array[i]);
    }
}

void arrayIter(int n){
    int array[n];
    for (int i = 0 ; i < n ; i++){
        if(i == 0){
            array[i] = 0;
        } else if (i == 1){
            array[i] = 1;
        } else { 
            array[i] = array[i-1] + array[i-2];
        }
        printf("%d ",array[i]);
    }

}

double input(){

    double num;

    char chara;

    if (scanf("%lf%c",&num,&chara)!= 2  || chara != '\n' || chara == ','){

        clear_buffer();

        printf("Input invalid! Masukkan angka : ");

        return input();

    } else {

        return num;

    }

}