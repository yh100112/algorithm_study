#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
const int INF = -987654321;
int n, m, visited[54][54], ret, _mx;
char a[54][54];
queue<pair<int,int>> q;

void go(int y, int x){
    while(q.size()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        _mx = max(_mx, visited[y][x]);
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue;
            if(a[ny][nx] == 'L'){
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny,nx});
            }
        }
    }
    return;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 'L'){
                _mx = INF;
                fill(&visited[0][0] , &visited[0][0] + 54 * 54, 0);
                visited[i][j] = 1;
                q.push({i,j});
                go(i,j);
                ret = max(ret, _mx);
            }
        }
    }
    cout << ret - 1 << '\n';
}