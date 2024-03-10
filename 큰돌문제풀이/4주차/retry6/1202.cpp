#include<bits/stdc++.h>
using namespace std;
int n, k, m, v, b;
long long ret;
vector<pair<int, int>> jewel;
vector<int> bag;

int main(){
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> m >> v; // 무게, 가격
        jewel.push_back({m,v});
    }
    for (int i = 0; i < k; ++i) {
        cin >> b;
        bag.push_back(b);
    }
    sort(bag.begin(), bag.end()); // bag - 담을 수 있는 무게 오름차순으로 정렬
    sort(jewel.begin(), jewel.end());

    priority_queue<int> pq;
    int j_idx = 0;
    for (int i = 0; i < k; ++i) {
        while (j_idx < n && bag[i] >= jewel[j_idx].first)
            pq.push(jewel[j_idx++].second);
        
        if (pq.size()) {
            ret += pq.top();
            pq.pop();        
        }
    }
    cout << ret << "\n";
    return 0;
}