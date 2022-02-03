#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ifstream fin("/home/kdy/C_C++_Projects/helloworldcpp/파일입출력/output.txt");

    //get()으로 한 글자씩 읽어오기
    // char c;
    // while(fin.get(c)){
    //     cout << c;
    // }
    // fin.close();

    //getline()으로 한 문장씩 읽어오기
    // char line[100];
    // while(fin.getline(line,sizeof(line))){
    //     cout << line << endl;
    // }
    // fin.close();
    
    //연산자 >> 로 읽어오기
    char line[100];
    while(fin.eof() != true){
        fin >> line;
        cout << line << endl;
    }
    fin.close();

    return 0;
}