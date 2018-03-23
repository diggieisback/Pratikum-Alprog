#include <stdio.h>
#include <stdbool.h>

int main(){
    int n;
    int count = 0;
    int list = 2;
    printf("Masukkan banyak bilangan : ");
    scanf("%d",&n);
    printf("%d bilangan prima pertama : ",n);
    while (count < n) {
        bool isprime = true;
        if (list == 2) {
            printf("%d ",list);
            count++;
        } else {
            for (int i = 2 ; i < list ; i ++){
                if (list % i == 0){
                    isprime = false;
                    break;
                }
            }
            if (isprime) {
                printf("%d ",list);
                count ++;
            }
        }
        list++;
    }
    return 0;
}