
#include <stdio.h>

#include <stdbool.h>

#include <stdlib.h>

#include <math.h>

#include <string.h>



void balok();

void bola();

void limas();

void prisma();

void tabung();

void menu();

double PHI=3.14;

double input();

void clear_buffer();

void reset();



int main(){

    printf("Selamat datang di program perhitungan luas permukaan dan volume bangun ruang! ");

    menu();

    return 0;

}



void menu(){

    double choice;

    int check;

    printf("Pilih bangun ruang:\n\n1.Balok\n2.Bola\n3.Limas segitiga sama sisi\n4.Prisma segitiga\n5.Tabung\n6.Exit Program\nPilihan : ");

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

            switch ((int)choice)

            {

                case 1:

                    balok();

                    break;

                case 2:

                    bola();

                    break;

                case 3:

                    limas();

                    break;

                case 4:

                    prisma();

                    break;

                case 5:

                    tabung();

                    break;

            }

            reset();

        }

    }else {

        system("cls");

        printf("Input invalid!\n");

        menu();

    }

}



void limas(){

    double volume,luasAlas,sisi,tinggi,luasTegak,luasPermukaan;

    printf("Masukkan sisi alas limas : ");

    sisi = input();

    printf("Masukkan tinggi limas : ");

    tinggi = input();

    printf("Masukkan luas sisi tegak :");

    luasTegak = input();

    double n = sisi * 3.0/2.0;

    luasAlas = sqrt(n*pow(n-sisi,3));

    volume = 1.0/3.0*luasAlas*tinggi;

    luasPermukaan = luasAlas + 3 * luasTegak;

    printf("\nVolume limas : %.2lf satuan\n",volume);

    printf("Luas permukaan limas : %.2lf satuan\n",luasPermukaan);

}



void prisma(){

    double volume,luasAlas,sisi1,sisi2,sisi3,tinggi,luasPermukaan;

    printf("Masukkan sisi alas 1 :");

    sisi1 = input();

    printf("Masukkan sisi alas 2 :");

    sisi2 = input();

    printf("Masukkan sisi alas 3 :");

    sisi3 = input();

    printf("Masukkan sisi tinggi :");

    tinggi = input();

    if(sisi1+ sisi2 == sisi3 || sisi1+sisi3 == sisi2 || sisi2 + sisi3 ==sisi1){

        system("cls");

        printf("Input invalid\n");

        prisma();

    }else{

        double s = 0.5 * (sisi1 + sisi2 + sisi3); 

        luasAlas = sqrt(s*(s-sisi1)*(s-sisi2)*(s-sisi3));

        volume = luasAlas * tinggi;

        luasPermukaan = 2 * luasAlas + sisi1 * tinggi + sisi2 * tinggi + sisi3 *tinggi;

        printf("\nVolume prisma : %.2lf satuan\n",volume);

        printf("Luas permukaan prisma: %.2lf satuan\n",luasPermukaan);

    }



}



void balok(){

    double panjang,lebar,tinggi,volume,luasPermukaan;

    printf("Masukkan panjang balok : ");

    panjang = input();

    printf("Masukkan lebar balok : ");

    lebar = input();

    printf("Masukkan tinggi balok :");

    tinggi = input();

    volume = panjang*lebar*tinggi;

    luasPermukaan = 2*(panjang*lebar+panjang*tinggi+tinggi*lebar);

    printf("\nVolume Balok : %.2lf satuan\n",volume);

    printf("Luas permukaan Balok : %.2lf satuan",luasPermukaan);

}



void bola(){

    double r,volume,luasPermukaan;

    printf("Masukkan panjang jari jari bola :");

    r = input();

    volume = 4.0/3.0*PHI*r*r*r;

    luasPermukaan = 4.0*PHI*r*r;

    printf("\nVolume Bola : %.2lf satuan\n",volume);

    printf("Luas permukaan Bola : %.2lf satuan",luasPermukaan);

}



void tabung(){

    double r,t,volume,luasPermukaan;

    printf("Masukkan panjang jari jari tabung : ");

    r = input();

    printf("Masukkan tinggi tabung : ");

    t = input();

    volume = PHI*r*r*t;

    luasPermukaan = 2*PHI*r*(r+t);

    printf("\n Volume Tabung : %.2lf satuan\n",volume);

    printf("Luas permukaan Tabung %.2lf satuan\n",luasPermukaan);

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
