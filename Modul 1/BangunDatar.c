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


int main(){
    menu();
    return 0;
}

void menu(){
    int choice;
    bangunDatar pilihan;
    printf("Pilih bangun datar:\n\n1.Persegi\n2.Segitiga\n3.Lingkaran\n4.Trapesium\n5.Jajar Genjang\n\nPilihan : ");
    scanf("%d",&choice);
    //Validasi dikuatkan(input float gagal,isi huruf di belakang error)
    switch (choice)
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
        case 6 :
            return;
            break;
        default:
            system("cls");
            printf("input invalid\n");
            menu();
    }
    printf("Bangun datar %s : \nLuas : %.2lf satuan\nKeliling : %.2lf satuan",pilihan.nama,pilihan.luas,pilihan.keliling);
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
    bangunDatar segitiga;
    double s1,s2,s3,s;
    printf("Masukkan semua sisi segitiga : ");
    s1 = input();
    s2 = input();
    s3 = input();
    segitiga.keliling = s1 + s2 + s3;
    s = 1.0/2.0 * segitiga.keliling;
    segitiga.luas = sqrt(s*(s-s1)*(s-s2)*(s-s3)); 
    strcpy(segitiga.nama,"Segitiga");
    return segitiga;
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
    bool valid = scanf("%lf",&num);
    clear_buffer();
    if (valid == 0){
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