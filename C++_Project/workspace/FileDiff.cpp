#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class Diff{
public:
    void FileDiff(string src,string dst){
        ifstream fin1;
        fin1.open("/home/kdy/C_C++_Projects/helloworldcpp/workspace/" + src );

        ifstream fin2;
        fin2.open("/home/kdy/C_C++_Projects/helloworldcpp/workspace/" + dst );

        char *line1 = new char[100];
        char *line2 = new char[100];
        int size = 100;


        while (true){
            if (fin1.fail()){
                cerr << "파일 없음" << endl;
                delete[] line1;
                delete[] line2;
                return;
            }
            while (fin1.getline(line1, size)){
                fin2.getline(line2,size);

                for(int i = 0;i < size; i++){
                    if(line1[i] != line2[i]){
                        cout << "Different!" << endl;
                        delete[] line1;
                        delete[] line2;
                        return;
                    }
                }
            }
            cout << "Same!" <<endl;
            delete[] line1;
            delete[] line2;
            
            fin1.close();
            fin2.close();
            break;
        }
    }
};


int main(){
    Diff diff;
    string language,method,src,dst;
    cin >> language >> method >> src >> dst;
    if(language == "c++"){
        if (method == "diff"){
            diff.FileDiff(src,dst);
        }
        else{
            cout << "diff만 가능" << endl;
            return 0;
        }
    }else{
        cout << "c++만 가능합니다." << endl;
        return 0;
    }
}