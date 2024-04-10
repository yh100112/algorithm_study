#include<bits/stdc++.h>
using namespace std;
int n, a, b;
vector<pair<int,int>> v;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end(), [](pair<int,int>& left, pair<int,int>& right){
        if (left.second == right.second)
            return left.first < right.first;
        return left.second < right.second;
    });

    int s = v[0].first;
    int e = v[0].second;
    int cnt = 1;
    for (int i = 1; i < v.size(); i++) {
        if (v[i].first < e) continue;
        s = v[i].first;
        e = v[i].second;
        cnt++;
    }
    cout << cnt << "\n";
}