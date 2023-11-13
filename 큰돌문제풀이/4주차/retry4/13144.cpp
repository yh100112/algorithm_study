#include<bits/stdc++.h>
using namespace std;
long long n, ans;
int arr[100004];
bool checked[100004];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    ans = n * (n + 1) / 2;
    int lt = 0;
    int rt = 1;
    checked[arr[lt]] = true;
    while(rt < n){
        if(checked[arr[rt]]){
            checked[arr[lt++]] = false;
            ans -= (n - rt);
        }
        else
            checked[arr[rt++]] = true;
    }
    cout << ans << '\n';
}