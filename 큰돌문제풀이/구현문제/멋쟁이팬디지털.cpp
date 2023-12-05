#include<bits/stdc++.h>
using namespace std;
string s, num;
int visited[10], n;
vector<long long> v;

bool check(int n){
    for(int i = 1; i <= n; i++)
        if(!visited[i]) return false;
    return true;
}

int main(){
    cin >> s >> n;
    for(int i = 0; i < s.length(); i++){
        if(num.length() == n){
            if(check(n)){
                v.push_back(stoll(num));
            }
            visited[num[0] - '0']--;
            num.erase(num.begin());
        }
        num += s[i];
        visited[s[i] - '0']++;
    }
    if(check(n))
        v.push_back(stoll(num));
    
    if(!v.size()) cout << -1 << '\n';
    else cout << *max_element(v.begin(), v.end()) << '\n';
}