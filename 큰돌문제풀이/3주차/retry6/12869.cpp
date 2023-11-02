#include<bits/stdc++.h>
using namespace std;
int n, a[3], visited[64][64][64];
const int attack[6][3] = {
    {9,3,1},
    {9,1,3},
    {3,9,1},
    {3,1,9},
    {1,3,9},
    {1,9,3}
};
struct A{
    int a,b,c;
};

void go(int a, int b, int c){
    visited[a][b][c] = 1;
    queue<struct A> q;
    q.push({a,b,c});

    while(q.size()){
        if(visited[0][0][0]) break;
        int x = q.front().a;
        int y = q.front().b;
        int z = q.front().c;
        q.pop();
        for(int i = 0; i < 6; i++){
            int nx = max(0, x - attack[i][0]);
            int ny = max(0, y - attack[i][1]);
            int nz = max(0, z - attack[i][2]);
            if(visited[nx][ny][nz]) continue;
            visited[nx][ny][nz] = visited[x][y][z] + 1;
            q.push({nx,ny,nz});
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    go(a[0], a[1], a[2]);
    cout << visited[0][0][0] - 1 << '\n';
}