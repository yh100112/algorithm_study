#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> v{1,2,3,4};
    int num;
    cin >> num;

    try{
        cout << v.at(num) << endl; //v.at(index) : index번째 원소를 반환한다.
    }catch(exception& e){
        cout << e.what()<<endl;
        cout<< "인덱스 오류 발생!"<<endl;
    }

    cout<<"program is still running" <<endl;
    //저기서 오류가 나도 예외를 처리했기 때문에 그 다음 try~catch를 통과한 후 코드들도 정상적으로 동작하고 끝낸다. 
    return 0;
}