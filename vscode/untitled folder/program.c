
#include <stdio.h>
#include <limits.h>  // For INT_MAX

int main() {
    int A;
    long long B;
    
    // Taking input for A and B
    printf("Enter an integer A: ");
    scanf("%d", &A);
    printf("Enter a long long integer B: ");
    scanf("%lld", &B);

    // Subtracting A from the maximum value of int
    long long result = (long long)INT_MAX - A;
    
    // Printing the result
    printf("The result of subtracting A from INT_MAX is: %lld\n", result);

    return 0;
}

}