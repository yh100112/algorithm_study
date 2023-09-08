#include<bits/stdc++.h>
using namespace std;
string s;
string cro[8] = {"c=","c-","dz=","d-","lj","nj","s=","z="};
int ret;

int main(){
    cin >> s;
    for(auto v : cro) {
        while(s.find(v) != string::npos) {
            s.replace(s.find(v), v.length(), "0");
            ret++;
        }
    }
    s.erase(remove(s.begin(), s.end(), '0'), s.end());
    ret += s.length();
    cout << ret <<"\n";
}