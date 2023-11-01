#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, m, a[54][54], ret = INF;
vector<pair<int,int>> home, chicken;
vector<vector<int>> chicken_list;

void combi(int idx, vector<int> v){
    if(v.size() == m){
        chicken_list.push_back(v);
        return;
    }
    for(int i = idx; i < chicken.size(); i++){
        v.push_back(i);
        combi(i + 1, v);
        v.pop_back();
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            if(a[i][j] == 1) home.push_back({i,j});
            if(a[i][j] == 2) chicken.push_back({i,j});
        }
    }

    vector<int> v;
    combi(0, v);

    for(vector<int> _list : chicken_list){
        int sum = 0; // 도시의 치킨거리
        for(auto _h : home){
            int dist = INF; // 집의 치킨거리
            for(int idx : _list){
                int temp = abs(_h.first - chicken[idx].first) + abs(_h.second - chicken[idx].second);
                dist = min(dist, temp);
            }
            sum += dist;
        }
        ret = min(ret, sum);
    }
    cout << ret << '\n';
}