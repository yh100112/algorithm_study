#include<bits/stdc++.h>
using namespace std;
int n, a, b, ret = 1;
vector<pair<int,int>> v;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        v.push_back({a,b}); // start, end
    }

    sort(v.begin(), v.end(), [](pair<int,int>& l, pair<int,int>& r){
        if(l.second == r.second)
            return l.first < r.first;
        else
            return l.second < r.second;
    });

    int l = v[0].first;
    int r = v[0].second;
    for(int i = 1; i < n; i++){
        if(v[i].first < r) continue;
        l = v[i].first;
        r = v[i].second;
        ret++;
    }
    cout << ret << '\n';
}