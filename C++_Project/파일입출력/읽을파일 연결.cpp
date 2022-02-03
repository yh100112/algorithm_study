#include<fstream>
#include<iostream>
using namespace std;

int main(){
    ifstream fin("/home/kdy/C_C++_Projects/helloworldcpp/파일입출력/input.txt");
    if(fin.fail() == true){
        cerr << "파일을 찾을 수 없음" << endl;
        return 1;
    }
    fin.close();
    return 0;
}