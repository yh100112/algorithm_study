#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
int n, k, l, a[104][104], visited[104][104], cnt, dir = 1;
int yy,xx,t;
char c;
vector<pair<int, char>> v;

int main(){
    cin >> n >> k;
    for(int i = 0; i < k; i++){
        cin >> yy >> xx;
        yy--, xx--;
        a[yy][xx] = 1; // 사과     
    }

    cin >> l;
    for(int i = 0; i < l; i++){
        cin >> t >> c;
        v.push_back({t,c});
    }

    deque<pair<int,int>> dq;
    dq.push_back({0,0});
    visited[0][0] = 1;

    int j = 0;
    int y = dq.back().first;
    int x = dq.back().second;
    while(true){
        cnt++;
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if(cnt == v[j].first){
            if(v[j].second == 'L') dir = (dir + 3) % 4;
            else dir = (dir + 1) % 4;
            j++;
        }
        if(ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx]) break;
        visited[ny][nx] = 1;
        dq.push_back({ny,nx});
        if(!a[ny][nx]){ // 사과 x
            visited[dq.front().first][dq.front().second] = 0;
            dq.pop_front();
        }
        if(a[ny][nx]) a[ny][nx] = 0;
        y = ny;
        x = nx;
    }
    cout << cnt << '\n';
}