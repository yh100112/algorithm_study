#include<bits/stdc++.h>
using namespace std;
int n, x, ret;
vector<int> v;

int main(){
    cin >> n;
    v.resize(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cin >> x;

    sort(v.begin(), v.end());
    int l = 0, r = n - 1;
    while(l < r){
        if(a[l] + a[r] == x)     r--, ret++;
        else if(a[l] + a[r] > x) r--;
        else if(a[l] + a[r] < x) l++;
    }
    cout << ret << '\n';
}