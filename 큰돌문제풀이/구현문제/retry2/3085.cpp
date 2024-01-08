#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
int n, visited[54][54], ret = -987654321;
string s[54];

void go(){
    int row_max = 0;
    int col_max = 0;
    // row
    for(int i = 0; i < n; i++){
        char c = s[i][0];
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(c != s[i][j]){
                c = s[i][j];
                if(cnt)
                    row_max = max(row_max, cnt);
                cnt = 0;
            }
            cnt++;
        }
        if(cnt) row_max = max(row_max, cnt);
    }

    // col
    for(int i = 0; i < n; i++){
        char c = s[0][i];
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(c != s[j][i]){
                c = s[j][i];
                if(cnt)
                    col_max = max(col_max, cnt);
                cnt = 0;
            }
            cnt++;
        }
        if(cnt) col_max = max(col_max, cnt);
    }

    int ans = max(row_max, col_max);
    ret = max(ans, ret);
}

void check(int y, int x){
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx]) continue;
        swap(s[y][x], s[ny][nx]);
        go();
        swap(s[y][x], s[ny][nx]);
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> s[i];
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            go();
            check(i,j);
        }
    }
    cout << ret << '\n';
}