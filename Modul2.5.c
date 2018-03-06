#include <stdio.h>

int fibonacci(int n);
void array(int n);

int main(){
    int n;
    scanf("%d",&n);
    array(n);
    return 0;
}

int fibonacci(int n){   
    if (n == 0){
        return 0;
    }else if (n == 1){
        return 1;
    } else {
       return fibonacci(n-2) + fibonacci(n-1);
    }
}

void array(int n){
    int array[n];
    printf("%d deret bilangan fibonacci : ",n);
    for (int i = 0;i < n; i++){
        array[i] = fibonacci(i);
        printf("%d ",array[i]);
    }
}