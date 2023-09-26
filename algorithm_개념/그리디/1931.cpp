#include<bits/stdc++.h>
using namespace std;
int n, from, to, cnt = 1;

int main(){
    cin >> n;
    vector<pair<int,int>> v;
    for(int i = 0; i < n; i++){
        cin >> from >> to;
        v.push_back({from, to});
    }
    
    sort(v.begin(), v.end(), [](pair<int,int>& left, pair<int,int>& right){
        if(left.second == right.second)
            return left.first < right.first;
        else
            return left.second < right.second;
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