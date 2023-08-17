#include<bits/stdc++.h>
using namespace std;
int n, m, ret, a[54][54], result = 987654321;
vector<vector<int>> chickenList; // 조합들을 저장해놔야 하기 때문에 중첩 vector
vector<pair<int,int>> _home, chicken;
void combi(int start, vector<int> v){
    if(v.size() == m){
        chickenList.push_back(v);
        return;
    }
    for(int i = start + i; i < chicken.size(); i++){
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
    return;
}

// 1 : 집, 2 : 치킨집
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
    for(vector<int> cList : chickenList){
    }
}