#include<bits/stdc++.h>
using namespace std;
int n, ret = 987654321, v[20][20], p[20][20];
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};

int setFlower(int y, int x){
    v[y][x] = 1;
    int s = p[y][x];
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        v[ny][nx] = 1;
        s += p[ny][nx];
    }
    return s;
}
void eraseFlower(int y, int x){
    v[y][x] = 0;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        v[ny][nx] = 0;
    }
}
bool check(int y, int x){
    if(v[y][x]) return 0;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= n || v[ny][nx]){
            return 0;
        }
    }
    return 1;
}

// cnt : 심은 꽃 개수, hap : 합
void flower(int cnt, int hap){
    if(cnt == 3){
        ret = min(ret, hap);
        return;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(check(i,j)){
                flower(cnt+1, hap + setFlower(i,j)); // 방문처리
                eraseFlower(i,j); // 백트래킹처럼 visited를 다시 0으로만드는 작업 수행
            }
        }
    }
}

// 백트래킹 응용문제
int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> p[i][j];
    flower(0,0);
    cout << ret;
}