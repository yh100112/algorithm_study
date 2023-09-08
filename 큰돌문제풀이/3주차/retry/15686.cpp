#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, m, ret = INF, a[54][54];
vector<pair<int,int>> home, chicken;
vector<vector<int>> chicken_pick;

void combi(int idx, vector<int> v){
    if(v.size() == m){
        chicken_pick.push_back(v);
        return;
    }
    for(int i = idx; i < chicken.size(); i++){
        v.push_back(i);
        combi(i+1, v);
        v.pop_back();
    }
}

int main(){
    cin >> n >> m; // 치킨집 : 최대 m개
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            if(a[i][j] == 1) home.push_back({i,j});
            if(a[i][j] == 2) chicken.push_back({i,j});
        }
    }

    vector<int> v;
    combi(0, v);
    // 치킨집 조합
    for(auto _chicken_pick : chicken_pick){
        int s = 0; // 도시의 치킨거리
        for(auto _home : home){
            int min_len = INF; // 집의 치킨거리
            for(auto chik : _chicken_pick) {
                int len = abs(_home.first - chicken[chik].first) + abs(_home.second - chicken[chik].second);
                min_len = min(len, min_len);
            }
            s += min_len;
        }
        ret = min(s, ret);
    }
    cout << ret << "\n";
}

/*
치킨거리 : 집과 가장 가까운 치킨집 사이의 거리
도시의 치킨 거리 = 모든 집의 치킨 거리의 합
도시의 정보는 0, 1, 2로 이루어져 있고, 0은 빈 칸, 1은 집, 2는 치킨집을 의미한다.
첫째 줄에 폐업시키지 않을 치킨집을 최대 M개를 골랐을 때, 도시의 치킨 거리의 최솟값을 출력한다.
*/