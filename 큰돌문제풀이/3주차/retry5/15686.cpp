#include<bits/stdc++.h>
using namespace std;
int n, m, a[54][54], ret = 987654321;
vector<pair<int,int>> home, chicken;
vector<vector<int>> List;

void combi(int idx, vector<int> b){
    if(b.size() == m){
        List.push_back(b);
        return;
    }
    for(int i = idx; i < chicken.size(); i++){
        b.push_back(i);
        combi(i + 1, b);
        b.pop_back();
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

    vector<int> b;
    combi(0, b);
    for(vector<int> _chicken_list : List){
        int chicken_distance = 0;
        for(pair<int,int> _home : home){
            int home_distance = 987654321;
            for(int idx : _chicken_list){
                int s = abs(chicken[idx].first - _home.first) + abs(chicken[idx].second - _home.second);
                home_distance = min(home_distance, s);
            }
            chicken_distance += home_distance;
        }
        ret = min(ret, chicken_distance);
    }
    cout << ret << '\n';
}