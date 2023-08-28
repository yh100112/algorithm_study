#include<bits/stdc++.h>
using namespace std;
#define y1 aaaa
#define x1 aaaaa
int n, m, x1, y1, x2, y2, visited[304][304];
char a[304][304];
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};

int main(){
    cin >> n >> m;
    cin >> y1 >> x1 >> y2 >> x2;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    queue<pair<int,int>> q;
    visited[y1-1][x1-1] = 1;
    q.push({y1-1,x1-1});
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue;
            if(a[ny][nx] == '1' || a[ny][nx] == '#'){
                visited[ny][nx] = visited[cur.first][cur.second] + 1;
                q.push({ny,nx});
            }
            else if(a[ny][nx] == '0'){
                visited[ny][nx] = visited[cur.first][cur.second];
                q.push({ny,nx});
            }
        }
    }
    cout << visited[y2-1][x2-1] - 1 << "\n";
}