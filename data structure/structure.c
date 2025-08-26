#include<stdio.h>
#include<strings.h>
struct student{
    char name[50];
    int age;
};
int main(){
    struct student s1;
    strcpy(s1.name,"Ashok");
    s1.age=19;
    printf("Name: %s\n",s1.name);
    printf("age: %d\n",s1.age);
    printf("size of struct is %zu in bytes\n ",sizeof(s1));
    int k=500;
    int *m=&k;
    printf("%d\n%p\n",*m,m);
    return 0;
}//find out the size of the structure
//take a variable k=500 and a pointer variabe n output should be 500 and address
