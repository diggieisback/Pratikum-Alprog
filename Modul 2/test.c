#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char *p = malloc( sizeof(char) * ( 4) );
    int len = 0;
    do{
        scanf("%c",&p[len]);
        len++;
    } while(p[len-1] != '\n');   
    
    for (int i = 0;i<len;i++){
        printf("%c",p[i]);
    }
}