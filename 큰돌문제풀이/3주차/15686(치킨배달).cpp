#include<bits/stdc++.h>
using namespace std;
int n, m, a[54][54], visited[54][54], result = INT_MAX;
vector<pair<int,int>> _home, chicken;
vector<vector<int>> checkList;

void combi(int start, vector<int> v){
    if(v.size() == m){
        checkList.push_back(v);
        return;
    }
    for(int i = start + 1; i < chicken.size(); i++){
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
    return;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            if(a[i][j] == 1) _home.push_back({i,j});
            if(a[i][j] == 2) chicken.push_back({i,j});
        }
    }

    vector<int> v;
    combi(-1, v);
    for(auto cList : checkList){ // 3개 고른 조합
        int ret = 0; // 도시의 치킨 거리
        for(auto home : _home){
            int _min = INT_MAX; // 집의 치킨 거리
            for(auto c : cList){ // 한개의 집과 치킨집들간의 치킨 거리 총 합
                int h = abs(home.first - chicken[c].first) + abs(home.second - chicken[c].second);                    
                _min = min(h, _min);
            }
            ret += _min;
        }
        result = min(ret, result);
    }
    cout << result << endl;
}