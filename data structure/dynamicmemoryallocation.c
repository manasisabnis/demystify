
#include <stdio.h>
#include <stdlib.h>
#include <malloc/malloc.h>
int main(){
    int *k;
    k=(int*)malloc(20);
    if(k==NULL){
        printf("Memory allocation is not possible");
        return 1;
    }
    printf("the size is %zu/n bytes",malloc_size(k));
    free(k);//before switch to calloc function 
    k=(int*)calloc(5,sizeof(int));// in this 5 is the number of elements we multiply it by 4 to get 20 bytes
    if(k==NULL){
        printf("contiguous Memory allocation is not possible");
        return 1;
    }
    printf("the size is %zu/n bytes",malloc_size(k));
    k=(int*)realloc(k,40);
    if(k==NULL){
        printf("realloc Memory allocation is not possible");
        return 1;
    }
    printf("the size is %zu/n bytes",malloc_size(k));
    free(k);
    return 0;


}