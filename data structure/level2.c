#include <stdio.h>
#include <stdbool.h>


bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main(){
    int n;
    scanf("%d", &n);

    int count = 0; 
    int sum = 0;
    int i = 2;      

    while (sum <= n) {
        if (isPrime(i)) {
            sum += i; 
            if (isPrime(sum) && sum <= n && sum > 2) {
                count++; 
            }
        }
        i++; 

    printf("%d\n", count); 

    return 0;
}}
    