#include<bits/stdc++.h>
using namespace std;
int dy1[] = {0, -1, 0, 1};
int dx1[] = {1, 0, -1, 0};
int dy2[] = {0,1,0,-1};
int dx2[] = {1,0,-1,0};
int n, m, t, a[54][54], temp[54][54], sum;
vector<pair<int,int>> v1, v2;

void move(){
    fill(&temp[0][0], &temp[0][0] + 54 * 54, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] <= 0) continue;
            int spread = a[i][j] / 5;
            int cnt = 0;
            for(int k = 0; k < 4; k++){
                int ny = i + dy1[k];
                int nx = j + dx1[k];
                if(ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == -1) continue;
                temp[ny][nx] += spread;
                cnt++;
            }
            a[i][j] -= (cnt * spread);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == -1) continue;
            a[i][j] += temp[i][j];
        }
    }
}

vector<pair<int,int>> chung(int sy, int sx, int dy[], int dx[]){
    vector<pair<int,int>> v;
    int cnt = 0;
    int y = sy;
    int x = sx;
    while(true){
        int ny = y + dy[cnt];
        int nx = x + dx[cnt];
        if(ny == sy && nx == sx) break;
        if(ny < 0 || ny >= n || nx < 0 || nx >= m){
            cnt++;
            ny = y + dy[cnt];
            nx = x + dx[cnt];
        }
        v.push_back({ny,nx});
        y = ny;
        x = nx;
    }
    return v;
}

void go(vector<pair<int,int>>& v){
    for(int i = v.size() - 1; i > 0; i--){
        a[v[i].first][v[i].second] = a[v[i - 1].first][v[i - 1].second];
    }
    a[v[0].first][v[0].second] = 0;
}

int main(){
    cin >> n >> m >> t;
    bool flag = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j] == -1){
                if(flag){
                    v1 = chung(i, j, dy1, dx1);
                    flag = false;
                }
                else{
                    v2 = chung(i, j, dy2, dx2);
                }
            }
        }
    }

    while(t--){
        move();
        go(v1);
        go(v2);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == -1) continue;
            sum += a[i][j];
        }
    }
    cout << sum << '\n';
}