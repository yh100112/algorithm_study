#include<bits/stdc++.h>
using namespace std;
int n, a[3], visited[64][64][64];
const int attack[6][3] = {
    {9, 3, 1},
    {9, 1, 3},
    {3, 9, 1},
    {3, 1, 9},
    {1, 3, 9},
    {1, 9, 3}
};

struct A{
    int a,b,c;
};
queue<A> q;

void go(){
    visited[a[0]][a[1]][a[2]] = 1;
    q.push({a[0], a[1], a[2]});

    while(q.size()){
        int a = q.front().a;
        int b = q.front().b;
        int c = q.front().c;
        q.pop();
        if(visited[0][0][0]){
            cout << visited[0][0][0] - 1 << '\n';
            return;
        }
        for(int i = 0; i < 6; i++){
            int na = max(0, a - attack[i][0]);
            int nb = max(0, b - attack[i][1]);
            int nc = max(0, c - attack[i][2]);
            if(visited[na][nb][nc]) continue;
            visited[na][nb][nc] = visited[a][b][c] + 1;
            q.push({na,nb,nc});
        } 
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    go(); 
}