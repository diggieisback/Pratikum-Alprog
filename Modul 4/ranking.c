#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    char nama[255];
    int nilai;
} Student;

int getStudent(Student students[]);
void bubbleSort(Student students[], int n);
void putToFile(Student students[], int n);

int main(){
    int count;
    Student *students = malloc( sizeof(Student) * (255) );
    count = getStudent(students);
    bubbleSort(students,count);
    for(int i = 0;i < count; i++)
    {
        printf("%s %d\n",students[i].nama,students[i].nilai);
    }
    putToFile(students,count);
}

int getStudent(Student students[]){
    int len = 0;
    FILE * fr;
    fr = fopen("asistenin.txt","r");
    Student myStudent;
    char nilai[5];
    while(fgets(myStudent.nama,255,fr)){
            int stringLength = strlen(myStudent.nama);
            myStudent.nama[stringLength - 1] = '\0';
            fgets(nilai,5,fr);
            stringLength = strlen(nilai);
            nilai[stringLength - 1] = '\0';            
            myStudent.nilai = atoi(nilai);
            students[len] = myStudent;
            len++;
        }
        fclose(fr);
    return len;
} 

void bubbleSort(Student students[], int n){
    int i, j;
    Student temp;
    for (i = 0; i < n-1; i++)      
         for (j = 0; j < n-i-1; j++) 
            if (students[j].nilai < students[j+1].nilai){
                temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;
    }
}

void putToFile(Student students[], int n){
    FILE * fw;
    FILE * fa;
    fw = fopen("asistenout.txt","w");
    fa = fopen("asistenout.txt","a+");
    char *hasil = malloc( sizeof(char) * (255) );
    fprintf(fw,"%s\n","Nilai Mata Kuliah Algoritma dan Pemrograman ");
    for (int i = 0; i < n-1; i++){
        sprintf(hasil,"%d. %s %d\n",i+1,students[i].nama,students[i].nilai);
        fprintf(fa,"%s",hasil);                 //print ke file
    }      
    fclose(fw);
    fclose(fa);
    return;
}