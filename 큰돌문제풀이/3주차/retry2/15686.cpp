#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, m, a[54][54], ret = INF;
vector<pair<int,int>> home, chicken;
vector<vector<int>> List;

void combi(int idx, vector<int> v){
    if(v.size() == m){
        List.push_back(v);
        return;
    }
    for(int i = idx; i < chicken.size(); i++){
        v.push_back(i);
        combi(i + 1, v);
        v.pop_back();
    }
}

int main(){
    cin >> n >> m; // n : 도시의 가로세로
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            if(a[i][j] == 1) home.push_back({i,j});
            if(a[i][j] == 2) chicken.push_back({i,j});
        }
    
    vector<int> b;
    combi(0, b);
    for(vector<int> _List : List){
        int city = 0;
        for(pair<int,int> _home : home){
            int home_min = INF;
            for(int _chicken : _List){
                int _mn = abs(_home.first - chicken[_chicken].first) + abs(_home.second - chicken[_chicken].second);
                home_min = min(_mn, home_min);
            }
            city += home_min;
        }
        ret = min(ret, city);
    }
    cout << ret << '\n';
}