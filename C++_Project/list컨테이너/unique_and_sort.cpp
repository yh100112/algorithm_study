#include<iostream>
#include<list>
#include<functional>

using namespace std;

//unique를 통해 자기 자신과 자신의 다음 노드가 동일한 인자이면 1개만 남기고 제거, 그후 sort로 정렬(string 타입으로 list를 선언했으므로 사전순으로 정렬)

int main(){
    list<string> lt;

    lt.push_back("b");
    lt.push_back("c");
    lt.push_back("a");
    lt.push_back("q");
    lt.push_back("a");
    lt.push_back("a");
    lt.push_back("a");
    lt.push_back("k");
    lt.push_back("j");
    lt.push_back("p");
    lt.push_back("q");
    lt.push_back("o");
    lt.push_back("e");
    lt.push_back("a");
    lt.push_back("a");

    list<string>::iterator iter;

    printf("origin) ");
    for(iter = lt.begin(); iter!= lt.end(); iter++){
        cout <<*iter << " ";
    }    
    cout << endl << endl;

    printf("unique) ");
    lt.unique();
    for(iter = lt.begin(); iter != lt.end(); iter++){
        cout << *iter << " ";
    }
    cout << endl << endl;

    cout << "sort) ";
    lt.sort();
    for(iter = lt.begin(); iter!= lt.end(); iter++){
        cout <<*iter << " ";
    }    
    cout << endl << endl;



    return 0;

}