#include<bits/stdc++.h>
using namespace std;
int n, p, d, ret;
vector<pair<int,int>> v;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p >> d;
        v.push_back({d,p}); // day, pay
    }
    sort(v.begin(), v.end()); // day 오름차순 정렬

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
        pq.push(v[i].second);
        if(pq.size() > v[i].first) {
            pq.pop();
        }
    }

    while(pq.size()) {
        ret += pq.top();
        pq.pop();
    }
    cout << ret << "\n";
}