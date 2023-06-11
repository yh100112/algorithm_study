#include<bits/stdc++.h>
using namespace std;
int n,m; // 1 <= n,m <= 100,000
string str;
map<string, int> m1;
map<int, string> m2;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> str;
        m1.insert({str,i+1});
        m2.insert({i+1,str});       
    }
    for(int i = 0; i < m; i++){
        cin >> str;
        if(atoi(str.c_str()) == 0) {
            cout << m1[str] << "\n";
        }
        else {
            cout << m2[stoi(str)] << "\n";
        }
    }
}