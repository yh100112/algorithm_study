#include<bits/stdc++.h>
using namespace std;
int n, m, cnt;
vector<int> v;

int main(){
    cin >> n >> m;
    v.resize(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    
    int l = 0;
    int r = 0;
    int sum = v[0];
    while(l < n && r < n){
        if(r < n && sum < m){
            sum += v[++r];
        }
        else if(sum == m){
            cnt++;
            sum -= v[l++];
        }
        else{
            sum -= v[l++];
        }
    }
    cout << cnt << '\n';
}