#include<bits/stdc++.h>
using namespace std;
int n, p, d, ret;
vector<pair<int,int>> v;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p >> d;
        v.push_back({p, d});
    }

    sort(v.begin(), v.end(), [](pair<int,int>& left, pair<int,int>& right){
        return left.second < right.second;
    });
    
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; ++i) {
        pq.push(v[i].first);
        if (pq.size() > v[i].second)
            pq.pop();
    }
    while(pq.size()) {
        ret += pq.top();
        pq.pop();
    }
    cout << ret << endl;
}