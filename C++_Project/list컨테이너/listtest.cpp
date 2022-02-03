#include<stdio.h>
#include<iostream>
#include<list>
using namespace std;

int main(){
    list<int> lt;
    lt.push_back(10);
    lt.push_back(20);
    lt.push_back(30);
    lt.push_back(40);
    lt.push_back(50);

    //while문으로 lt의 앞부분을 다 pop해서 리스트 안의 값이 없어질 때까지 돔
    while(lt.begin() != lt.end()){
        int fd = lt.front();
        printf("%d ",fd);
        lt.pop_front();
    }


}