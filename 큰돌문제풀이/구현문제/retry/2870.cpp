#include<bits/stdc++.h>
using namespace std;
int n;
string s;
vector<string> v;

void go(string num){
    if(num.front() == '0'){
        while(num.size() && num.front() == '0'){
            num.erase(num.begin());
        }
        if(num.size() == 0) num = "0";
        v.push_back(num);
    }
    else{
        v.push_back(num);
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        string num = "";
        int flag = 0;
        for(int j = 0; j < s.length(); j++){
            if('0' <= s[j] && s[j] <= '9'){
                num += s[j];
                flag = 1;
            }
            else if(flag){
                flag = 0;
                go(num);
                num = "";
            }
        }
        if(flag) go(num);
    }
    sort(v.begin(), v.end(), [](string left, string right){
        if(left.size() == right.size())
            return left < right;
        return left.size() < right.size();
    });
    for(auto i : v)
        cout << i << '\n';
}