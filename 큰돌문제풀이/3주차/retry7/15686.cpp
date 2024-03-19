#include<bits/stdc++.h>
using namespace std;
int n, m, a[54][54], ret = 987654321;
vector<pair<int,int>> chicken, home;
vector<vector<int>> chicken_list;

void combi(vector<int>& v, int idx) {
    if (v.size() == m) {
        chicken_list.push_back(v);
        return;
    }

    for (int i = idx + 1; i < chicken.size(); ++i) {
        v.push_back(i);
        combi(v, i);
        v.pop_back();
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 1) home.push_back({i,j});
            if (a[i][j] == 2) chicken.push_back({i,j});
        }
    }
    vector<int> v;
    combi(v, -1);

    // 집과 가장 가까운 치킨집과의 거리 = 치킨 거리  ->  최대 M개의 치킨집이므로 M개를 다 비교하는게 최솟값을 구할 수 있음
    // 도시의 치킨 거리 = 모든 집의 치킨 거리의 합
    for (auto& c_list : chicken_list) {
        int chicken_sum = 0;
        for (auto& h_ : home) {
            int home_chicken_dist = 987654321; // 치킨 거리
            for (auto& c_ : c_list) {
                int dist = abs(h_.first - chicken[c_].first) + abs(h_.second - chicken[c_].second);
                home_chicken_dist = min(home_chicken_dist, dist);
            }
            chicken_sum += home_chicken_dist;
        }
        ret = min(chicken_sum, ret);
    }
    cout << ret << "\n";
}