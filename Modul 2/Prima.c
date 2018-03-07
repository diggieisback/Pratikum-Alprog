#include <stdio.h>
#include <stdbool.h>

int main(){
    int n;
    printf("Masukkan banyak bilangan: ");
    scanf("%d",&n);
    int angka[n];
    bool isPrime[n];
    printf("Masukkan bilangan :");
    for(int i = 0; i < n; i++){
        scanf("%d",&angka[i]);
    }
    printf("Bilangan prima yang ada di barisan bilangan tersebut adalah : ");
    for (int i=0;i < n; i++){
        for(int j = 2; j < angka[i] ; j++ ){
            if (angka[i] % j == 0 || angka [i] == 1){
                isPrime[i] = false;
                break;
            } else {
                isPrime[i] = true;
            }
        }
    }
    for (int i=0; i<n ; i++){
        if (isPrime[i] == true){
            printf("%d ", angka[i]);
        }
    }
    return 0;
}