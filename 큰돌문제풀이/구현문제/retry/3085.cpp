#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
const int INF = 987654321;
int n, y, x, ret = -INF, visited[52][52];
char a[52][52];

int check(){
    int max_row = 0;
    int max_col = 0;
    for(int i = 0; i < n; i++){
        int len = 1;
        int row = -INF;
        for(int j = 1; j < n; j++){
            if(a[i][j] == a[i][j - 1]){
                len++;
                if(j == n - 1)
                    row = max(row, len);
            }
            else{
                row = max(row, len);
                len = 1;
            }
        }
        max_row = max(max_row, row);
    }
    for(int i = 0; i < n; i++){
        int len = 1;
        int col = -INF;
        for(int j = 1; j < n; j++){
            if(a[j][i] == a[j - 1][i]) {
                len++;
                if(j == n - 1)
                    col = max(col, len);
            }
            else {
                col = max(col, len);
                len = 1;
            }
        }
        max_col = max(max_col, col);
    }
    return max(max_row, max_col);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            check();
            visited[i][j] = 1;
            y = i, x = j;
            for(int dir = 0; dir < 4; dir++){
                int ny = y + dy[dir];
                int nx = x + dx[dir];
                if(ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx]) continue;
                if(a[y][x] == a[ny][nx]) continue;
                swap(a[y][x], a[ny][nx]);
                ret = max(ret, check());
                swap(a[y][x], a[ny][nx]);
            }
        }
    }
    cout << ret << '\n';
}