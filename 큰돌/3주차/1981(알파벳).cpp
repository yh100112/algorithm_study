/*
2 4
CAAB
ADCB

3
*/
#include<bits/stdc++.h>
using namespace std;
const int max_n = 21;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
int R, C, x, y, visited[max_n][max_n], alpha[26];
char a[max_n][max_n];
queue<pair<int,int>> q;

int main(){
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> a[i][j];
        }
    }

    q.push({0,0});
    visited[0][0] = 1;
    alpha[a[0][0] - 'A']++;

    while(q.size()){
        tie(y,x) = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= R || nx < 0 || nx >= C || visited[ny][nx]) continue;
            if(alpha[a[ny][nx] - 'A']) continue;
            visited[ny][nx] = visited[y][x] + 1;
            alpha[a[ny][nx] - 'A']++;
            q.push({ny,nx});
        }
    }

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cout << visited[i][j];
        }
        cout << "\n";
    }
}