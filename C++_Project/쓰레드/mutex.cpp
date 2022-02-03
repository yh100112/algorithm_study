#include<stdio.h>
#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

class Node
{
private:
    int data = 0;
public:
    void addData(int data){
        this->data += data;
    }

    int getData(){
        return this->data;
    }
};

mutex _mutex;

void thread_function(Node* node){
    for(int i=0;i <= 1000; i++){
        _mutex.lock();
        node->addData(i);
        _mutex.unlock();
    }
}

int main(){
    Node node;
    thread t1(thread_function,&node);
    thread t2(thread_function,&node);

    t1.join();
    t2.join();

    printf("최종 노드 값 : %d\n",node.getData());
    return 0;
}