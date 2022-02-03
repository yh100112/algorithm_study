#include<iostream>
#include<string>

using namespace std;

class Person{
private:
    int x,y;
public:
    // x = 3;  이렇게는 private에 접근 불가
    // y = 4;
    double radius = 2;
    
    //1.private에 이렇게 접근가능
    Person(){
        x = 3;
        y = 4;
    }

    //2.private에 이렇게 접근 가능
    int getNumX(){
        return x;
    }

    int getNumY(){
        return y;
    }
};

int main(){
    Person test;
    cout << test.radius << endl;
    // cout << test.x << endl; => 이건 private에 접근 불가
    cout << test.getNumX()<<endl;
    cout << test.getNumY()<<endl;

    
    return 0;
}