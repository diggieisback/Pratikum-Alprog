#include <stdio.h>

#include <string.h>

#include <math.h>

#include <stdbool.h>

#include <stdlib.h>



typedef struct bangunDatar

{

    double luas;

    double keliling; 

    char nama[20];

} bangunDatar;



double PHI=3.14;



void menu();

bangunDatar persegi();

bangunDatar segitiga();

bangunDatar lingkaran();

bangunDatar jajarGenjang();

bangunDatar trapesium();

double input();

void clear_buffer();

void reset();



int main(){

    menu();

    return 0;

}



void menu(){

    float choice;

    int check;



    bangunDatar pilihan;

    printf("Pilih bangun datar:\n\n1.Persegi\n2.Segitiga\n3.Lingkaran\n4.Trapesium\n5.Jajar Genjang\n6.Exit Program\n\nPilihan : ");

    choice = input();

    check = ceil(choice);

    if (check == choice){

        if (choice>5 || choice < 1){

                if (choice == 6){

                        return;

                } else {

                    system("cls");

                    printf("Input invalid !\n");

                    menu();

                }

        } else {

        //Validasi dikuatkan(input float gagal,isi huruf di belakang error)

            switch ((int)choice)

            {

                case 1:

                    pilihan = persegi();

                    break;

                case 2:

                    pilihan = segitiga();

                    break;

                case 3:

                    pilihan = lingkaran();

                    break;

                case 4:

                    pilihan = trapesium();

                    break;

                case 5:

                    pilihan = jajarGenjang();

                    break;

            }

            printf("\n\nBangun datar %s : \nLuas : %.2lf satuan\nKeliling : %.2lf satuan\n\n",pilihan.nama,pilihan.luas,pilihan.keliling);

            reset();

        }

    }else {

        system("cls");

        printf("Input invalid!\n");

        menu();

    }

}



bangunDatar persegi(){

    bangunDatar persegi;

    double panjang,tinggi;

    printf("Masukkan panjang : ");

    panjang = input();

    printf("Masukkan tinggi : ");

    tinggi = input();

    persegi.luas = panjang * tinggi;

    persegi.keliling = 2 * (panjang + tinggi);

    strcpy(persegi.nama,"Persegi");

    return persegi;

}



bangunDatar lingkaran(){

    bangunDatar lingkaran;

    double r;

    printf("Masukkan panjang jari-jari : ");

    r = input();

    lingkaran.luas = PHI * r * r;

    lingkaran.keliling = 2 * PHI * r;

    strcpy(lingkaran.nama,"Lingkaran");

    return lingkaran;

}



bangunDatar segitiga(){

    bangunDatar bangunSegitiga;

    double s1,s2,s3,s;

    printf("Masukkan sisi 1 : ");

    s1 = input();

    printf("Masukkan sisi 2 : ");

    s2 = input();

    printf("Masukkan sisi 3 : ");

    s3 = input();

    if(s1+ s2 == s3 || s1+s3 == s2 || s2 + s3 ==s1){

        system("cls");

        printf("Input invalid\n");

        bangunSegitiga = segitiga();

    }else{

        bangunSegitiga.keliling = s1 + s2 + s3;

        s = 0.5 * bangunSegitiga.keliling;

        bangunSegitiga.luas = sqrt(s*(s-s1)*(s-s2)*(s-s3)); 

        strcpy(bangunSegitiga.nama,"Segitiga");

    }

    return bangunSegitiga;

}



bangunDatar jajarGenjang(){

    bangunDatar jajarGenjang;

    double s1,s2,t;

    printf("Masukkan sisi alas jajar genjang : ");

    s1 = input();

    printf("Masukkan sisi miring jajar genjang : ");

    s2 = input();

    printf("Masukkan tinggi jajar genjang : ");

    t = input();

    jajarGenjang.luas = s1 * t;

    jajarGenjang.keliling = 2 * s1 + 2 * s2 ;

    strcpy(jajarGenjang.nama,"Jajar Genjang");

    return jajarGenjang;

}



bangunDatar trapesium(){

    bangunDatar trapesium;

    double alas,sisiSejajar,sisiLain1,sisiLain2,tinggi;

    printf("Masukkan alas : ");

    alas = input();

    printf("Masukkan sisi sejajar dengan alas : ");

    sisiSejajar = input();

    printf("Masukkan 2 buah sisi lainnya : ");

    sisiLain1 = input();

    sisiLain2 = input();

    printf("Masukkan tinggi :");

    tinggi = input();

    trapesium.keliling = alas + sisiSejajar + sisiLain1 + sisiLain2;

    trapesium.luas = 1.0/2.0 * (alas + sisiSejajar) * tinggi;

    strcpy(trapesium.nama,"Trapesium");

    return trapesium;

}



double input(){

    double num;

    char chara;

    if (scanf("%lf%c",&num,&chara)!= 2 || num<=0 || chara != '\n' || chara == ','){

        fflush(stdin);

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
