#include<iostream>
#include<map>
#include<cstring>

using namespace std;



int main(){
    map<string,string> m;
    while(true){
        string input = "";
        string str_arr[1000]={"",};
        int str_cnt = 0;
        char *str_buff = new char[1000];
        cout << "< ";
        cin.get(str_buff,100).ignore(100,'\n'); // c언어 문자열 입력 방식

        char *tok = strtok(str_buff," ");
        while(tok != nullptr){
            str_arr[str_cnt++] = string(tok);
            tok =  strtok(nullptr, " ");
        }
        
        string method = str_arr[0];
        string key = str_arr[1];
        string value = str_arr[2];
        if(method == "exit"){
            cout << "(종료됨)" << endl;
            delete[] str_buff;
            break;
        }else if(method == "set"){
            m[key] = value;
            cout << "OK" << endl;
        }else if(method == "get"){

            if(m.find(key) != m.end()){
                cout << m[key] << endl;
            }else{
                cout << "not found" << endl;
            }

        }else{
            cout << "invalid command" << endl;
        }

        delete[] str_buff;
    }



    return 0;
}