#include<bits/stdc++.h>
using namespace std;
int n, k, a[100004], ret = -987654321;

int main(){
    cin >> n >> k;
    for(int i  = 0; i < n; i++)
        cin >> a[i];
    
    int l = 0;
    int r = 0;
    int sum = 0;
    int cnt = 0;
    while(r < n){
        if(cnt < k){
            sum += a[r++];
            cnt++;
        }
        if(cnt == k){
            ret = max(ret, sum);
            sum -= a[l++];
            cnt--;
        }
    }
    cout << ret << '\n';
}