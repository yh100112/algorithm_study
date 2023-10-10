#include<bits/stdc++.h>
using namespace std;
int n, x,cnt;
vector<int> v;

int main(){
    cin >> n;
    v.resize(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    cin >> x;
    sort(v.begin(), v.end());
    int l = 0;
    int r = n - 1;
    while(l < r){
        int sum = v[l] + v[r];
        if(sum < x){
            l++;
        }
        else if(sum == x){
            cnt++;
            r--;   
        }
        else if(sum > x){
            r--;
        }
    }
    cout << cnt << '\n';
}