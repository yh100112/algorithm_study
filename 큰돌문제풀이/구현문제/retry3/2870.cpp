#include<bits/stdc++.h>
using namespace std;
int n;
string s;
vector<int> v;

void check_num(){
    string num = "";
    for(int i = 0; i < s.length(); ++i){
        if('0' <= s[i] && s[i] <= '9'){
            if(s[i] == '0'){
                if(num.size()){
                    if(num.back() == '0'){
                        num.erase(num.length() - 1);
                    }
                    else{
                        num += s[i];
                    }
                }
                else{
                    num += s[i];
                }
            }
            else{
                num += s[i];
            }
        }
        else{
            if(num.size()){
                v.push_back(stoi(num));
                num = "";
            }
        }
    }
    if(num.size())
        v.push_back(stoi(num));
}

int main(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> s;
        check_num();
    }

    sort(v.begin(), v.end());
    for(auto& i : v)
        cout << i << "\n";
}