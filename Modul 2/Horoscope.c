#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TRUE  1
#define FALSE  0

typedef struct birthday{
    int day;
    int month;
} birthdayStruct;

char userZodiac[20];
birthdayStruct input_birthday();
char * get_zodiac(int month,int day);
birthdayStruct check_birth_valid(int day,int month);
void print_error(int checkDay,int checkMonth);
void reset();
void menu();
void clear_buffer();

int main(){
    menu();
    return 0;
}

void menu(){
    
    char myZodiac[20];

    birthdayStruct myBirthday;
    birthdayStruct check;
    
    myBirthday = input_birthday();
    clear_buffer();
    check = check_birth_valid(myBirthday.day,myBirthday.month);
    if ((!check.day) || (!check.month)){
            
        print_error(check.day,check.month);
            
    } else {
        get_zodiac(myBirthday.month,myBirthday.day);
        strcpy(myZodiac,userZodiac);
        printf("%s",myZodiac);
    }
    reset();    
}

birthdayStruct input_birthday(){
    
    birthdayStruct birthday;//return 3 value makanya pake struct (lihat diatas)
    
    printf ("Masukkan tanggal dan bulan lahir (DD MM)  : ");
    scanf("%d %d",&birthday.day,&birthday.month);
    printf("\n");
    
    return birthday;
}

char * get_zodiac(int month,int day){
    
    if ((day >= 21 && month == 3) || (day<=19 && month == 4)) {
        strcpy(userZodiac,"Aries");
    } else if ((day >= 20 && month == 4) || (day <= 20 && month == 5)) {
        strcpy(userZodiac,"Taurus");
    } else if ((day >= 21 && month == 5) || (day <= 20 && month == 6)) {
        strcpy(userZodiac,"Gemini");
    } else if ((day >= 21 && month == 6) || (day <= 22 && month == 7)) {
        strcpy(userZodiac,"Cancer");
    } else if ((day >= 23 && month == 7) || (day <= 22 && month == 8)) {
        strcpy(userZodiac,"Leo");
    } else if ((day >= 23 && month == 8) || (day <= 22 && month == 9)) {
        strcpy(userZodiac,"Virgo");
    } else if ((day >= 23 && month == 9) || (day <=22 && month == 10)) {
        strcpy(userZodiac,"Libra");
    } else if ((day >= 23 && month == 10) || (day <=21 && month == 11)) {
        strcpy(userZodiac,"Scorpio");
    } else if ((day >= 22 && month == 11) || (day <= 21 && month == 12)) {
        strcpy(userZodiac,"Sagitarius");
    } else if ((day >= 22 && month == 12 ) || (day <= 19 && month == 1)) {
        strcpy(userZodiac,"Capricorn");
    } else if ((day >= 20 && month == 1 ) || (day <=18 && month == 2)) {
        strcpy(userZodiac,"Aquarius");
    } else {
        strcpy(userZodiac,"Pisces");
    }
    return userZodiac;
}

birthdayStruct check_birth_valid(int day,int month){
    
    birthdayStruct valid;
    valid.day = TRUE;
    valid.month = TRUE;
    
    if (day > 31 || day < 1 )  {
        valid.day = FALSE;
    } if (day > 30 && month == 4) {
        valid.day = FALSE;
    } if (day > 30 && month == 6) {
        valid.day = FALSE;
    } if (day > 30 && month == 9) {
        valid.day = FALSE;
    } if (day > 30 && month == 11) {
        valid.day = FALSE;
    } if (day > 29 && month == 2){ 
        valid.day = FALSE;
    } if (month > 12 || month < 1){
        valid.month = FALSE;
    } 

    return valid;
}

void print_error(int checkDay,int checkMonth){
    
    printf("\n\t\t            [PESAN ERROR :]\n\n");
    
    if (!checkDay) {//error bagian hari
        printf("\t    - Maaf tanggal yang anda masukkan tidak valid -\n\a");
    }

    if (!checkMonth) {//error bagian bulan
        printf("\t     - Maaf bulan yang anda masukkan tidak valid -\n\a");
    }    


    return;
}

void reset(){

    int valid_reset;
    char parameter[1];

    printf("\n\n\t\t     Kembali ke menu awal?[Y/N] ");
    gets(parameter);
    
    if (!(strcmp(parameter,"Y")) || !(strcmp(parameter,"y"))){
        
        system("cls");
        menu();

    } else if (!(strcmp(parameter,"N")) || !(strcmp(parameter,"n"))){
        
        return;

    } else {
        system("cls");
        printf("\t\t            Invalid Input !\n\a");
        reset();
    }
}

void clear_buffer(){

    char c;

    while ((c = getchar()) != '\n' && c != EOF) ; 

    

}
