#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ofstream fout("/home/kdy/C_C++_Projects/helloworldcpp/파일입출력/output.txt");
    fout << "hello world!\n";
    fout.put('A');
    fout.put('B');
    fout.close();
    return 0;
}