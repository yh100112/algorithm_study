#include<bits/stdc++.h>
using namespace std;
int n;
string s, num;
vector<string> ret;

void go(){
    while(true){
        if(num.size() && num.front() == '0') num.erase(num.begin());
        else break;
    }
    if(num.size() == 0) num = "0";
    ret.push_back(num);
    num = "";
}

bool cmp(string s1, string s2){
    if(s1.size() == s2.size())
        return s1 < s2;
    return s1.size() < s2.size();
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        num = "";
        for(int j = 0; j < s.size(); j++){
            if(s[j] < 65) num += s[j];
            else if(num.size()) go();
        }
        if(num.size() > 0) go();
    }

    sort(ret.begin(), ret.end(), cmp);
    for(auto v : ret)
        cout << v << "\n";
}