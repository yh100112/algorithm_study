#include<bits/stdc++.h>
using namespace std;
#define time ff
#define y1 cc
int n, k, l, y, x, t, ret, idx, dir = 1;
int a[104][104], visited[104][104], time;
char c;
deque<pair<int, int>> dq;
vector<pair<int,int>> _time;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
int main(){
    cin >> n >> k;
    for(int i = 0; i < k; i++){
        cin >> y >> x;
        a[--y][--x] = 1;
    }
    cin >> l;
    for(int i = 0; i < l; i++){
        cin >> t >> c;
        if(c == 'D') _time.push_back({t, 1});
        else _time.push_back({t,3});
    }

    dq.push_back({0, 0});
    while(dq.size()){
        time++;
        tie(y, x) = dq.front(); // 머리를 맨 앞에 넣는 이유 -> dq하나로 bfs를 돌기 위해
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if(ny >= n || ny < 0 || nx >= n || nx < 0 || visited[ny][nx]) break;
        if(!a[ny][nx]){
            visited[dq.back().first][dq.back().second] = 0; // 끝부분 : 꼬리 삭제
            dq.pop_back();
        }
        else
            a[ny][nx] = 0;
        
        visited[ny][nx] = 1;
        dq.push_front({ny,nx}); // 머리 추가
        if(time == _time[idx].first){
            dir = (dir + _time[idx].second) % 4; // 이야 이거 참신하다.
            idx++;
        }
    }

}