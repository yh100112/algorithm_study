#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
int n, visited[54][54], ret = -INF;
char a[54][54];

void counting(){
    for(int i = 0; i < n; i++){ // 가로 합
        int cnt = 1;
        for(int j = 1; j < n; j++){
            if(a[i][j - 1] == a[i][j])
                cnt++;
            else{
                ret = max(ret, cnt);
                cnt = 1;
            }
        }
        ret = max(ret, cnt);
    }
    for(int i = 0; i < n; i++){ // 세로 합
        int cnt = 1;
        for(int j = 1; j < n; j++){
            if(a[j - 1][i] == a[j][i]){
                cnt++;
            }
            else{
                ret = max(ret, cnt);
                cnt = 1;
            }
        }
        ret = max(ret, cnt);
    }
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
            counting();
            for(int dir = 0; dir < 4; dir++){
                int ny = i + dy[dir];
                int nx = j + dx[dir];
                if(ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx]) continue;
                if(a[i][j] != a[ny][nx]) {
                    swap(a[i][j], a[ny][nx]);
                    counting();
                    swap(a[i][j], a[ny][nx]);
                }
            }
            visited[i][j] = 1;
        }
    }
    cout << ret << '\n';
}