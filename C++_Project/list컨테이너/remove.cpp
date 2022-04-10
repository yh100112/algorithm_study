#include<iostream>
#include<list>

using namespace std;

//remove_if(predicate)로 원소의 값이 100~200 사이인 값을 제거하고, remove(10)을 통해 원소의 값이 10인 원소들을 제거함.

bool predicate(int num){
    return num >= 100 && num <= 200;
}

int main(){
    list<int> lt;
    lt.push_back(10);
    lt.push_back(20);
    lt.push_back(108);
    lt.push_back(60);
    lt.push_back(10);
    lt.push_back(100);
    lt.push_back(40);    
    lt.push_back(50);
    lt.push_back(10);
    lt.push_back(109);
    lt.push_back(30);    
    lt.push_back(220);
    lt.push_back(10);

    list<int>::iterator iter;

    printf("origin) ");
    for(iter = lt.begin(); iter != lt.end(); iter++){
        printf("%d ",*iter);
    }
    printf("\n\n");

    //predicate함수가 참이면 remove한다
    //100~200사이 원소 제거
    lt.remove_if(predicate);

    cout << "test) ";
    for(iter = lt.begin(); iter != lt.end(); iter++){
        cout << *iter <<" ";
    }
    cout << endl << endl;

    lt.remove(10);
    for(iter = lt.begin(); iter != lt.end(); iter++){
        cout << *iter <<" ";
    }
    cout << endl << endl;
    return 0;

}