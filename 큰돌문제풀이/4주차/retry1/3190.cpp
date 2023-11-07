#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
int n, k, a, b, l, board[104][104], visited[104][104], cur = 1, t, idx;
char c;
queue<pair<int,char>> way;
deque<pair<int,int>> dq;

int main(){
    cin >> n;
    cin >> k;
    for(int i = 0; i < k; i++){
        cin >> a >> b;
        a--, b--;
        board[a][b] = 1; // apple
    }
    cin >> l;
    for(int i = 0; i < l; i++){
        cin >> a >> c; // time, direction
        way.push({a,c});
    }

    dq.push_back({0,0});
    visited[0][0] = 1;

    while(true){
        t++;
        int y = dq.front().first;
        int x = dq.front().second;
        int ny = y + dy[cur];
        int nx = x + dx[cur];
        if(ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx]) break;
        dq.push_front({ny,nx});
        visited[ny][nx] = 1;
        if(board[ny][nx] == 0){
            visited[dq.back().first][dq.back().second] = 0;
            dq.pop_back();
        }
        else
            board[ny][nx] = 0;
        if(way.size() && way.front().first == t){
            if(way.front().second == 'D') 
                cur = (cur + 1) % 4;
            else 
                cur = (cur + 3) % 4;
            way.pop();
        }
    }
    cout << t << '\n';
}