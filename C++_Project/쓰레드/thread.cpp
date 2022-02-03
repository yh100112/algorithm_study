#include<stdio.h>
#include<iostream>
#include<thread>
using namespace std;

void thread_function(int count){
    for(int i=0; i < count; i++){
        printf("i / count = %d / %d\n",i,count);
        this_thread::sleep_for(chrono::milliseconds(10)); // 쓰레드의 비활성 상태 대기, 10ms
    }
}

int main(){
    thread _t1(thread_function, 10); // thread_function함수를 호출하고 10을 파라미터로 넘긴다.
    thread _t2(thread_function, 10);
    _t1.join();
    _t2.join();
    printf("main thread \n");
    return 0;
}