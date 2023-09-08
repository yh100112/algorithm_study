#include<bits/stdc++.h>
using namespace std;
string str;
stack<char> s;

int main(){
    cin >> str;
    int sum = 1;
    int ret = 0;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '('){
            s.push('(');
            sum *= 2;
        }
        else if(str[i] == '['){
            s.push('[');
            sum *= 3;
        }
        else if(str[i] == ')'){
            if(s.empty() || s.top() != '('){
                ret = 0; break;
            }
            if(str[i-1] == '('){
                ret += sum;
            }
            sum /= 2;
            s.pop();
        }
        else if(str[i] == ']'){
            if(s.empty() || s.top() != '['){
                ret = 0; break;
            }
            if(str[i-1] == '['){
                ret += sum;
            }
            sum /= 3;
            s.pop();
        }
    }
    if(s.empty())
        cout << ret << "\n";
    else
        cout << 0 << "\n";
}