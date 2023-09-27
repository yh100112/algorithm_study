#include<bits/stdc++.h>
using namespace std;
#define start aaaa
#define end aaa
int n, m, sum, cnt, start, end;
vector<int> v;

int main(){
    cin >> n >> m;
    v.resize(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    sum = v[0]; 
    while(start != n && end != n){
        if(sum == m){
            sum -= v[start];
            start++, cnt++;
        }
        else if(sum < m){
            end++;
            sum += v[end];
        }
        else if(sum > m) {
            sum -= v[start];
            start++;
        }
    }
    cout << cnt << '\n';
}