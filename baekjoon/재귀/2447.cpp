#include<stdio.h>
#include<iostream>
using namespace std;

void star(int n){
    if(n == 1){
        printf("*");
        return;
    }
    int cnt = 0;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cnt++;
            if(cnt == 5){
                printf(" ");
                continue;
            }
            star(n/3);
        }
        printf("\n");
    }
    cnt = 0;
    
}

int main(){
    int n;
    scanf("%d",&n);
    star(n);
}