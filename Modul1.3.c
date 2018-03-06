#include <stdio.h>

void balok();
void bola();
void limas();
void prisma();
void tabung();
void menu();
double PHI=3.14;

int main(){
    printf("Selamat datang di program perhitungan luas permukaan dan volume bangun ruang! ");
    menu();
}

void menu(){
    int choice;
    printf("Pilih bangun ruang:\n\n1.Balok\n2.Bola\n3.Limas segitiga sama sisi\n4.Prisma segitiga\n5.Tabung\n\nPilihan : ");
    scanf("%d",&choice);
    switch (choice)
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
}

void balok(){
    double panjang,lebar,tinggi;
    printf("Masukkan panjang balok : ");
    scanf("%lf",&panjang);
    printf("Masukkan lebar balok : ");
    scanf("%lf",&lebar);
    printf("Masukkan tinggi balok :");
    scanf("%lf",&tinggi);
    printf("\nVolume Balok : %.2lf satuan\n",panjang*lebar*tinggi);
    printf("Luas permukaan Balok : %.2lf satuan",2*(panjang*lebar+panjang*tinggi+tinggi*lebar));
}

void bola(){
    double r;
    printf("Masukkan panjang jari jari bola :");
    scanf("%lf",&r);
    printf("\nVolume Bola : %.2lf satuan\n",4.0/3.0*PHI*r*r*r);
    printf("Luas permukaan Bola : %.2lf satuan",4.0*PHI*r*r);
}

void tabung(){
    double r,t;
    printf("Masukkan panjang jari jari tabung : ");
    scanf("%lf",r);
    printf("Masukkan tinggi tabung : ");
    scanf("%lf",t);
    printf("\n Volume Tabung : %.2lf satuan\n",PHI*r*r*t);
    printf("Luas permukaan Tabung %.2lf satuan\n",2*PHI*r*);
}