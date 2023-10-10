#include<bits/stdc++.h>
using namespace std;
int n, a, b;
vector<pair<int,int>> v;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        v.push_back({a,b}); // arrive, check time
    }
    sort(v.begin(), v.end());
    int l = v[0].first;
    int r = l + v[0].second;
    for(int i = 1; i < n; i++){
        l = max(v[i].first, r);
        r = l + v[i].second;
    }
    cout << r << '\n';
}