#include<bits/stdc++.h>
using namespace std;
const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};
int n, k, l, a[104][104], visited[104][104], ret, aa, bb;
queue<pair<int,char>> direction;
queue<pair<int,int>> q, snake;

int main(){
    cin >> n; // 보드 크기
    cin >> k; // 사과 갯수
    for(int i = 0; i < k; i++){
        cin >> aa >> bb;
        aa--, bb--;
        a[aa][bb] = 1; // 사과
    }
    cin >> l; // 뱀의 방향 변환 횟수
    for(int i = 0; i < l; i++){
        int t;
        char d;
        cin >> t >> d;
        direction.push({t,d});
    }
    
    q.push({0,0});
    snake.push({0,0});
    visited[0][0] = 1;

    int cur = 0;
    while(q.size()){
        ret++;
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        int ny = y + dy[cur % 4];
        int nx = x + dx[cur % 4];
        if(ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx])
            break;
        q.push({ny,nx});
        snake.push({ny,nx});
        visited[ny][nx] = 1;
        if(a[ny][nx] == 0){ // 사과 X
            auto e = snake.front();
            snake.pop();
            visited[e.first][e.second] = 0;
        }
        if(direction.front().first == ret){
            if(direction.front().second == 'L'){
                cur--;
                if(cur < 0) cur += 4;   
            }
            else
                cur++;
            direction.pop();
        }
    }
    cout << ret << '\n';
}