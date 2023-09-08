#include<bits/stdc++.h>
using namespace std;
const int max_n = 1501;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
int visited_swan[max_n][max_n], visited[max_n][max_n], R, C, day, swanY, swanX, y ,x;
char a[max_n][max_n];
queue<pair<int,int>> waterQ, water_tempQ, swanQ, swan_tempQ;
string s;
void Qclear(queue<pair<int,int>>& q){
    queue<pair<int,int>> empty;
    swap(q,empty);
}
void water_melting(){
    while(waterQ.size()){
        tie(y,x) = waterQ.front();
        waterQ.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= R || nx < 0 || nx >= C || visited[ny][nx]) continue;
            if(a[ny][nx] == 'X'){ // 빙하
                visited[ny][nx] = 1;
                water_tempQ.push({ny,nx}); // 빙하인 부분들
                a[ny][nx] = '.'; // 빙하 -> 물로 변경
            }
        }
    }
}
bool move_swan(){
    while(swanQ.size()){
        tie(y, x) = swanQ.front();
        swanQ.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= R || nx < 0 || nx >= C || visited_swan[ny][nx]) continue;
            visited_swan[ny][nx] = 1;
            if(a[ny][nx] == '.') swanQ.push({ny,nx}); // 물 -> 이동
            else if(a[ny][nx] == 'X') swan_tempQ.push({ny,nx}); // 빙하
            else if(a[ny][nx] == 'L') return true; // 백조를 만났다 
        }
    }
    return false; // 백조를 안 만났다
}

int main(){
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        cin >> s;
        for(int j = 0; j < C; j++){
            a[i][j] = s[j];
            if(a[i][j] == 'L')
                swanY = i, swanX = j; // 백조의 위치
            if(a[i][j] == '.' || a[i][j] == 'L') // 물 or 백조
                visited[i][j] = 1, waterQ.push({i, j}); // 백조가 있는 위치도 물 위이므로 물로 체크 -> waterQ에 물 위치 모두 들어감
        }
    }
    swanQ.push({swanY, swanX});
    visited_swan[swanY][swanX] = 1;
    // 백조는 물이있는곳은 한번에 쭉 갈 수 있음
    while(true){
        if(move_swan()) break;
        water_melting();
        waterQ = water_tempQ; // 빙하 부분부터 다시 bfs 시작
        swanQ = swan_tempQ; // 빙하 부분부터 다시 bfs시작
        Qclear(water_tempQ);
        Qclear(swan_tempQ);
        day++;
    }
    cout << day << "\n";
}