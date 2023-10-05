#include<bits/stdc++.h>
using namespace std;
int n, from, to, cnt = 1;
vector<pair<int,int>> v;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> from >> to;
        v.push_back({from, to});
    }
    sort(v.begin(), v.end(), [](pair<int,int>& l, pair<int,int>& r){
        if(l.second == r.second)
            return l.first < r.first;
        return l.second < r.second;
    });

    from = v[0].first;
    to = v[0].second;
    for(int i = 1; i < n; i++){
        if(v[i].first < to) continue;
        from = v[i].first;
        to = v[i].second;
        cnt++;
    }
    cout << cnt << '\n';
}