#include<bits/stdc++.h>
using namespace std;
int n;
string s;
vector<string> v;

void go(string num){
    while(num.size() && num[0] == '0'){
        num.erase(num.begin());
    }
    if(num.size() == 0) num = "0";
    v.push_back(num);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        string num = "";
        for(int j = 0; j < s.size(); j++){
            if(num.size() && s[j] > '9') {
                go(num);
                num = "";
            }
            else if(s[j] <= '9'){
                num += s[j];
            }
        }
        if(num.size())
            go(num);
    }

    sort(v.begin(), v.end(), [](string& left, string& right){
        if(left.size() == right.size())
            return left < right;
        return left.size() < right.size();
    });


    for(auto i : v)
        cout << i << '\n';
}