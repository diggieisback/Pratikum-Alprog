#include <stdio.h>
#include <string.h>
#include <math.h>

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


int main(){
    menu();
    return 0;
}

void menu(){
    int choice;
    bangunDatar pilihan;
    printf("Pilih bangun datar:\n\n1.Persegi\n2.Segitiga\n3.Lingkaran\n4.Trapesium\n5.Jajar Genjang\n\nPilihan : ");
    scanf("%d",&choice);
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
    }
    printf("Bangun datar %s : \nLuas : %.2lf satuan\nKeliling : %.2lf satuan",pilihan.nama,pilihan.luas,pilihan.keliling);
}

bangunDatar persegi(){
    bangunDatar persegi;
    double panjang,tinggi;
    printf("Masukkan panjang : ");
    scanf("%lf",&panjang);
    printf("Masukkan tinggi : ");
    scanf("%lf",&tinggi);
    persegi.luas = panjang * tinggi;
    persegi.keliling = 2 * (panjang + tinggi);
    strcpy(persegi.nama,"Persegi");
    return persegi;
}

bangunDatar lingkaran(){
    bangunDatar lingkaran;
    double r;
    printf("Masukkan panjang jari-jari : ");
    scanf("%lf",&r);
    lingkaran.luas = PHI * r * r;
    lingkaran.keliling = 2 * PHI * r;
    strcpy(lingkaran.nama,"Lingkaran");
    return lingkaran;
}

bangunDatar segitiga(){
    bangunDatar segitiga;
    double s1,s2,s3,s;
    printf("Masukkan semua sisi segitiga : ");
    scanf("%lf %lf %lf",&s1,&s2,&s3);
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
    scanf("%lf",&s1);
    printf("Masukkan sisi miring jajar genjang : ");
    scanf("%lf",&s2);
    printf("Masukkan tinggi jajar genjang : ");
    scanf("%lf", &t);
    jajarGenjang.luas = s1 * t;
    jajarGenjang.keliling = 2 * s1 + 2 * s2 ;
    strcpy(jajarGenjang.nama,"Jajar Genjang");
    return jajarGenjang;
}

bangunDatar trapesium(){
    bangunDatar trapesium;
    double alas,sisiSejajar,sisiLain1,sisiLain2,tinggi;
    printf("Masukkan alas : ");
    scanf("%lf",&alas);
    printf("Masukkan sisi sejajar dengan alas : ");
    scanf("%lf",&sisiSejajar);
    printf("Masukkan 2 buah sisi lainnya : ");
    scanf("%lf %lf",&sisiLain1,&sisiLain2);
    printf("Masukkan tinggi :");
    scanf("%lf",&tinggi);
    trapesium.keliling = alas + sisiSejajar + sisiLain1 + sisiLain2;
    trapesium.luas = 1.0/2.0 * (alas + sisiSejajar) * tinggi;
    strcpy(trapesium.nama,"Trapesium");
    return trapesium;
}