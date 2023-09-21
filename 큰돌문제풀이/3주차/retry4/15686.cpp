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

    // chicken combi
    vector<int> b;
    combi(0, b);
    for(vector<int> _chicken : chicken_list){
        int city_min = 0;
        for(pair<int,int> _home : home){
            int home_min = INF; //chicken 거리
            for(auto p : _chicken){
                int temp = abs(chicken[p].first - _home.first) + abs(chicken[p].second - _home.second);
                home_min = min(home_min, temp);
            }
            city_min += home_min;
        }
        ret = min(ret, city_min);
    }
    cout << ret << '\n';
}