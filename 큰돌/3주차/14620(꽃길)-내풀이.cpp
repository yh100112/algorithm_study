#include<bits/stdc++.h>
using namespace std;
int n, ret = 987654321, money, a[12][12], visited[12][12];
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
vector<pair<int,int>> flower; // 꽃 씨앗 위치

bool go(){
    for(auto idx : flower){
        money += a[idx.first][idx.second]; // 씨앗위치
        for(int i = 0; i < 4; i++){
            int ny = idx.first + dy[i];
            int nx = idx.second + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx]) return false;
            visited[ny][nx] = 1;
            money += a[ny][nx];
        }
    }
    return true;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];
    for(int i = 0; i < n*n; i++){
        for(int j = i+1; j < n*n; j++){
            for(int k = j+1; k < n*n; k++){
                flower.push_back({i / n, i % n});
                flower.push_back({j / n, j % n});
                flower.push_back({k / n, k % n});
                if(go()){
                    ret = min(ret, money);
                }
                fill(&visited[0][0], &visited[0][0] + 12*12, 0);
                flower.clear();
                money = 0;
            }
        }
    }
    cout << ret << "\n";
}