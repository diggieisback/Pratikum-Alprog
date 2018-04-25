#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double input();
void clear_buffer();
void reset();

typedef struct emp
{
    int gajiHarian;
    int gajiPerJam;
    int jamKerja; 
    int jamLembur;
} Emp;

int main(){
    Emp employee;
    employee.gajiPerJam = 1500;
    printf("Masukkan jam kerja pegawai :");
    employee.jamKerja = input();
    if(employee.jamKerja > 8){ 
        employee.jamLembur = employee.jamKerja - 8;
        employee.gajiHarian = employee.gajiPerJam * 8 + employee.gajiPerJam * 10 * employee.jamLembur;
    } else {
        employee.gajiHarian = employee.gajiPerJam * employee.jamKerja;
    }
    printf("Gaji harian pegawai : %d",employee.gajiHarian);
    reset();
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

        main();



    } else if (!(strcmp(parameter,"N")) || !(strcmp(parameter,"n"))){

        

        return;



    } else {

        system("cls");

        printf("Invalid Input !\n\a");

        reset();

    }

}
