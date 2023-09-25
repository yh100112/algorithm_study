#include<bits/stdc++.h>
using namespace std;
int fromt, to, n, idx = 0, ret = 1;

int main(){
    cin >> n;
    vector<pair<int,int>> v;
    for(int i = 0; i < n; i++){
        cin >> from >> to;
        v.push_back({to,from});
    }
    sort(v.begin(), v.end()); // 끝점을 기준으로 정렬
    from = v[0].second;
    to = v[0].first;
    for(int i = 1; i < n; i++){
        if(v[i].second < to) continue; // 다음 회의의 시작점이 이전 회의의 끝점보다 앞이면 안됨
        from = v[i].second;
        to = v[i].first;
        ret++;
    }
    cout << ret << '\n';
}