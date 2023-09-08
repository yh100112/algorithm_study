#include<bits/stdc++.h>
using namespace std;
string str;
stack<char> s;

int main(){
    cin >> str;
    int sum = 0; // 누적해서 더해지는 값
    int num = 1; // 곱해질 값

    for(int i = 0; i < str.length(); i++){
        if(str[i] == '(') {
            num *= 2; // ( 곱하기
            s.push(str[i]);
        }
        else if (str[i] == '[') {
            num *= 3; // [ 대괄호 곱하기
            s.push(str[i]);
        }
        else if (str[i] == ')') {
            if(s.empty() || s.top() != '(') { // 올바르지 않은 괄호쌍
                sum = 0; break;
            }
            if(str[i - 1] == '(') { //! 바로 이 부분!! 내가 생각하지 못한 포인트 !! -> str과 stack은 다르다!!
                sum += num; // 괄호쌍이 맞다면 sum에 값을 더함
            }
            s.pop();
            num /= 2; // 괄호쌍이 사라지므로 2로 나눔
        }
        else {
            if(s.empty() || s.top() != '[') { // 올바르지 않은 괄호쌍
                sum = 0; break;
            }
            if(str[i - 1] == '[') {
                sum += num; // 괄호쌍이 맞다면 sum에 값을 더함
            }
            s.pop();
            num /= 3; // 괄호쌍이 사라지므로 2로 나눔
        }
    }
    if (s.empty()) {
        cout << sum;
    }
    else {
        cout << 0;
    }
}