#include<stdio.h>
#include<stdlib.h>

char *ptr;

int size = 1;

void add(char c){
    int n = sizeof(ptr);
    if(sizeof(ptr) == size){
        size *= 2;
        ptr = realloc(ptr,size * sizeof(char));
    }
    ptr[n] = c;
}

int main(){
    ptr = (char*)malloc(sizeof(char));
    add('a');
    add('b');
    add('c');
    printf("%d", size);
    return 0;
}