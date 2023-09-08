#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    getline(cin, str);
    for(int i = 0; i < str.length(); i++){
        if('a' <= str[i] && str[i] <= 'z') {
            if (str[i] + 13 > 'z') str[i] += 13 - 26;
            else                   str[i] = str[i] + 13;
        }
        else if('A' <= str[i] && str[i] <= 'Z') {
            if (str[i] + 13 > 'Z') str[i] += 13 - 26;
            else                   str[i] = str[i] + 13;
        }
    }
    cout << str;

}