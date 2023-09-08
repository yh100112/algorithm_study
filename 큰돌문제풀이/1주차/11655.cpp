#include<bits/stdc++.h>
using namespace std;
string str;

int main(){
    getline(cin, str);
    for(int i = 0; i < str.length(); i++){
        if ('A' <= str[i] && str[i] <= 'Z') {
            if (str[i] > 'Z' - 13) {
                str[i] = 64 + (13 - ('Z' - str[i]));
            }
            else {
                str[i] += 13;
            }
        }
        else if ('a' <= str[i] && str[i] <= 'z') {
            if (str[i] > 'z' - 13) {
                str[i] = 96 + (13 - ('z' - str[i]));
            }
            else {
                str[i] += 13;
            }
        }
    }
    cout << str << "\n";
}