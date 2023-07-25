#include<bits/stdc++.h>
using namespace std;
#define prev deok
int n, o, A, B, asum, bsum;
string s, prev;

string print(int sum){
    string minute = "00" + to_string(sum / 60);
    string sec = "00" + to_string(sum % 60);
    return minute.substr(minute.size() - 2,2) + ":" + sec.substr(sec.size() - 2,2);
}

int changeToInt(string s){
    return stoi(s.substr(0,2)) * 60 + stoi(s.substr(3,2));
}

void go(int& sum, string s){
    sum += ((changeToInt(s) - changeToInt(prev)));
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> o >> s;
        if(A > B) go(asum, s);
        else if(A < B) go(bsum, s);
        o == 1 ? A++ : B++;
        prev = s;
    }
    if(A > B) go(asum, "48:00");
    else if(A < B) go(bsum, "48:00");

    cout << print(asum) << "\n";
    cout << print(bsum) << "\n";
}