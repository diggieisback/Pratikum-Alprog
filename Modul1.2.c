#include <stdio.h>

void menu;

typedef struct bangunDatar
{
    double luas;
    double keliling; 
} bangunDatar;

bangunDatar persegi();
bangunDatar segitiga();
bangunDatar lingkaran();

int main(){

    return 0;
}

void menu(){
    int choice;
    bangunDatar pilihan;
    printf("Pilih bangun ruang:\n\n1.Balok\n2.Bola\n3.Limas segitiga sama sisi\n4.Prisma segitiga\n5.Tabung\n\nPilihan : ");
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
}

