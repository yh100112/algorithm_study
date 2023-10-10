#include<bits/stdc++.h>
using namespace std;
int n, m, cnt = 0;
vector<int> v;

int main(){
    cin >> n >> m;
    v.resize(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    
    int s = 0;
    int e = 0;
    int sum = v[0];
    while(s < n && e < n){
        if(e < n && sum < m){
            e++;
            sum += v[e];
        }
        else if(sum == m){
            cnt++;
            sum -= v[s];
            s++;
        }
        else{
            sum -= v[s];
            s++;
        }
    }
    cout << cnt << '\n';
}