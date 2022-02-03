#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main(){
    string language,method,src,dst;
    cin >> language >> method >> src >> dst;
    if(language == "c++"){
        if (method == "copy"){
            ifstream fin;
            fin.open("/home/kdy/C_C++_Projects/helloworldcpp/workspace/" + src );

            string line;
            while (true){
                if (fin.fail()){
                    cerr << "파일 없음" << endl;
                    return 0;
                }
                ofstream fout("/home/kdy/C_C++_Projects/helloworldcpp/workspace/" + dst);
                while (getline(fin, line)){
                    fout << line << endl;
                }
                fin.close();
                fout.close();
                cout << "파일 복사 완료" << endl;
                break;
            }
        }
        else{
            cout << "copy만 가능" << endl;
            return 0;
        }
    }else{
        cout << "c++만 가능합니다." << endl;
        return 0;
    }


    return 0;
}