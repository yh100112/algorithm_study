#include<bits/stdc++.h>
using namespace std;
int n, x, y, ret;
vector<pair<int,int>> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        v.push_back({x,y});
    }

    sort(v.begin(), v.end()); // 시작 위치 기준으로 오름차순

    int from  = v[0].first;
    int to = v[0].second;
    bool flag = false;
    for (int i = 1; i < n; ++i) {
        if (v[i].first < to && to < v[i].second) {
            to = v[i].second;
        }
        else if (v[i].first == to) {
            to = v[i].second;
        }
        else if (v[i].first > to) {
            ret += (to - from);
            from = v[i].first;
            to = v[i].second;
        }
    }
    ret += (to - from);
    cout << ret << "\n";
}