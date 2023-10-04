#include<bits/stdc++.h>
using namespace std;
int n, m, a[10004], cnt;

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    int l = 0;
    int r = 0;
    int sum = a[0];
    while(l < n && r < n){
        if(r < n && sum < m){
            r++;
            sum += a[r];
        }
        else if(sum == m){
            cnt++;
            sum -= a[l];
            l++;
        }
        else{
            sum -= a[l];
            l++;
        }
    }
    cout << cnt << '\n';
}