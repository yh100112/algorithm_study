#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
int n, l, r, a[54][54], visited[54][54], day, sum;

void go(int y, int x, vector<pair<int,int>>& v){
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx]) continue;
        if(l <= abs(a[ny][nx] - a[y][x]) && abs(a[ny][nx] - a[y][x]) <= r){
            v.push_back({ny,nx});
            visited[ny][nx] = 1;
            sum += a[ny][nx];
            go(ny, nx, v);
        }
    }
}

int main(){
    cin >> n >> l >> r;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    while(true){
        fill(&visited[0][0], &visited[0][0] + 54*54, 0);
        bool flag = false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(visited[i][j]) continue;
                vector<pair<int,int>> v;
                sum = a[i][j];
                v.push_back({i,j});
                visited[i][j] = 1;
                go(i, j, v);

                if(v.size() == 1) continue;
                for(auto _v : v)
                    a[_v.first][_v.second] = sum / v.size();
                flag = true;
            }
        }
        if(!flag) break;
        day++;
    }
    cout << day << '\n';
}