#include<bits/stdc++.h>
using namespace std;
int n, x, cnt;
vector<int> v;

int main(){
    cin >> n;
    v.resize(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    cin >> x;
    
    sort(v.begin(), v.end());
    int l = 0;
    int r = n - 1;
    while(l < r){
        if(v[l] + v[r] < x){
            l++;
        }
        else if(v[l] + v[r] == x){
            cnt++;
            r--;
        }
        else{
            r--;
        }
    }
    cout << cnt << '\n';
}