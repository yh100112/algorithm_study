#include<bits/stdc++.h>
using namespace std;
long long n, a[100004], s, e, visited[100004], cnt;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    while(e < n){
        if(!visited[a[e]]){
            visited[a[e++]]++;
        }
        else{
            cnt += (e - s);
            visited[a[s++]]--;
        }
    }
    cnt += (long long)(e - s) * (e - s + 1) / 2;
    cout << cnt << '\n';
}