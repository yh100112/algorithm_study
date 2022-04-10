#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class Copy{
public:
    void FileCopy(string src,string dst){
        ifstream fin;
        fin.open("/home/kdy/C_C++_Projects/helloworldcpp/workspace/" + src );

        char *line = new char[100];
        int size = 100;

        while (true){
            if (fin.fail()){
                cerr << "파일 없음" << endl;
                delete[] line;
                return;
            }
            ofstream fout("/home/kdy/C_C++_Projects/helloworldcpp/workspace/" + dst);
            while (fin.getline(line, size)){
                fout << line << endl;
            }
            delete[] line;
            
            fin.close();
            fout.close();
            cout << "파일 복사 완료" << endl;
            break;
        }
    }
};

//파일의 내용을 읽을 때 메모리 동적 할당 사용
int main(){
    Copy copy;
    string language,method,src,dst;
    cin >> language >> method >> src >> dst;
    if(language == "c++"){
        if (method == "copy"){
            copy.FileCopy(src,dst);
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