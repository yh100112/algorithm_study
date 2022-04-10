#include <iostream>
#include <string>

using namespace std;

int main(){
    cout << "Please enter your name : ";
    string name;
    cin >> name;

    const string greeting = "Hello, " + name + "!";
    
    const int pad = 1; //인사말을 둘러싼 공백의 개수

    //출력할 열과 행의 개수
    const int rows = pad * 2 + 3;
    typedef string::size_type s_size;
    const s_size cols = greeting.size() + pad * 2 + 2; //std라는 네임스페이스에 속한 string이라는 기능을 의미 , string이라는 클래스에 속한 size_type이라는 기능을 사용하겠다는 의미
                                                                        //size_type으로 지정하는 이유 : cols에 greeting의 문자 개수를 길이와 상관없이 담으려고
    
    cout << endl;
    for(int r = 0; r != rows; r++){
        s_size c = 0;
        while(c != cols){
            if( (r == pad + 1) &&  (c == pad + 1)){
                cout << greeting;
                c += greeting.size();
            }else{
                if ( r==0 || r==rows-1 || c==0 ||c==cols-1){
                    cout << "*";
                }else{
                    cout << " ";
                }
                c++;
            }
        }
        cout << endl;
    }
    return 0;
}