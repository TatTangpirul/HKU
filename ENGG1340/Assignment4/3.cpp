#include<stdio.h>
#include<stdlib.h>

int *arr;

int size = 1;
int len = 0;

void display(){
    printf("[%d] ", size);
    for(int i=0;i<len;i++){
        if(i != len-1) printf(" %d", arr[i]);
        else printf(" %d\n", arr[i]);
    }
}
void add(char c){
    if(len+1 == size){
        size *= 2;
        arr = (int*)realloc(arr, size * sizeof(int));
    }
    arr[len] = c;
    len++;
    display();
}
int top() {return arr[len];}
int pop(){
    len--;
    return arr[len];
}
int empty() {return len == 0;}

int main(){
    arr = (int*)calloc(1, sizeof(int));
    char *str = NULL;
    size_t l = 0;
    int len = getline(&str, &l, stdin);
    str[l-1] = '\0';
    l--;
    
    for(int i=0;i<l;i++){
        if(str[i] != '+' && str[i] != '-' && str[i] != '=') add(str[i] - '0');
        else{
            int b = pop(), a = pop();
            if(str[i] == '+') add(a+b);
            else if(str[i] == '-'){
                add(a-b);
            }
            else return 0;
        }
    }
    printf("%d", size);
    return 0;
}