#include<bits/stdc++.h>
using namespace std;
int n, start, end;
vector<pair<int,int>> meet;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    meet.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> meet[i].first >> meet[i].second;
    sort(meet.begin(), meet.end(), [](pair<int,int>& left, pair<int,int>& right){
        if (left.second == right.second)
            return left.first < right.first;
        return left.second < right.second;
    });

    int from = meet[0].first;
    int to = meet[0].second;
    int cnt = 1;
    for (int i = 1; i < n; ++i) {
        if (to > meet[i].first) continue;
        from = meet[i].first;
        to = meet[i].second;
        ++cnt;
    }
    cout << cnt << "\n";
}