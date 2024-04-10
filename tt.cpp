#include<bits/stdc++.h>
using namespace std;
long long n, k, a, ret, m, v;
vector<pair<int,int>> jewel;
vector<int> bag;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> m >> v;
        jewel.push_back({m, v});
    }
    for (int i = 0; i < k; i++) {
        cin >> a;
        bag.push_back(a);
    }
    sort(bag.begin(), bag.end());
    sort(jewel.begin(), jewel.end());

    priority_queue<int> pq;
    int idx = 0;
    for (int i = 0; i < bag.size(); i++) {
        while(idx < n && bag[i] >= jewel[idx].first) {
            pq.push(jewel[idx].second);
            idx++;
        }
        if (pq.size()) {
            ret += pq.top();
            pq.pop();
        }
    }
    cout << ret << "\n";
}