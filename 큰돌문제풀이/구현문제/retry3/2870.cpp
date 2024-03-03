#include<bits/stdc++.h>
using namespace std;
string s;
int n;
vector<string> v;

void check(){
    string num = "";
    for (int i = 0; i < s.length(); ++i) {
        if ('a' <= s[i] && s[i] <= 'z') {
            if (num.size()) {
                while(num.front() == '0')
                    num.erase(num.begin());
                if(num.size() == 0)
                    num += '0';
                v.push_back(num);
                num = "";
            }
        }
        else {
            num += s[i];
        }
    }
    if (num.size()) {
        while(num.front() == '0')
            num.erase(num.begin());
        if(num.size() == 0)
            num += '0';
        v.push_back(num);
    }
}

int main(){
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        check();
    }

    sort(v.begin(), v.end(), [](string& left, string& right){
        if (left.size() == right.size())
            return left < right;
        else
            return left.size() < right.size();
    });

    for(auto& i : v)
        cout << i << "\n";
}