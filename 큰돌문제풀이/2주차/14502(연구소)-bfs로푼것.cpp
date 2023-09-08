#include<bits/stdc++.h>
using namespace std;
#define Y first
#define X second
int n,m;
int wall;
int ret;
int board[10][10], visited[10][10];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
vector<pair<int,int>> wallList, virusList;

int bfs(){
    queue<pair<int,int>> q;
    fill(&visited[0][0], &visited[0][0] + 10*10, 0);
    for(auto b : virusList){
        q.push({b.first,b.second});
        visited[b.first][b.second] = 1;
    }
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int ny = cur.Y + dy[i];
            int nx = cur.X + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(board[ny][nx] == 0 && visited[ny][nx] == 0){
                visited[ny][nx] = 1;
                q.push({ny,nx});
            }
        }
    }

    int cnt = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(board[i][j] == 0 && !visited[i][j]) cnt++;
    return cnt;
}

int main(){
    cin >> n >> m; // 세로,가로
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
            if(board[i][j] == 0) wallList.push_back({i,j});
            if(board[i][j] == 2) virusList.push_back({i,j});
        }
    }
    for(int i = 0; i < wallList.size(); i++){
        for(int j = 0; j < i; j++){
            for(int k = 0; k < j; k++){
                board[wallList[i].first][wallList[i].second] = 1;
                board[wallList[j].first][wallList[j].second] = 1;
                board[wallList[k].first][wallList[k].second] = 1;
                ret = max(ret, bfs());
                board[wallList[i].first][wallList[i].second] = 0;
                board[wallList[j].first][wallList[j].second] = 0;
                board[wallList[k].first][wallList[k].second] = 0;
            }
        }
    }
    cout << ret << endl;
}
