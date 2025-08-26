#include <stdio.h>

int fib(int x) {
    if (x == 0) {
        return 0;
    } else if (x == 1) {
        return 1;
    } else {
        return fib(x - 1) + fib(x - 2);
    }
}

int main() {
    int n;
    printf("Enter number");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("%d ", fib(i));
    }
    return 0;
}
// recursion deals with stack memory