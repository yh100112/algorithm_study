#include<bits/stdc++.h>
using namespace std;
#define y1 aaa
#define x1 aaaa
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
int n, m, y1, x1, y2, x2, visited[304][304], cnt;
char a[304][304];

int main(){
    cin >> n >> m;
    cin >> y1 >> x1 >> y2 >> x2;
    y1--, x1--, y2--, x2--;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];

    queue<pair<int,int>> q;
    q.push({y1,x1});
    visited[y1][x1] = 1;
    while(a[y2][x2] != '0'){
        cnt++;
        queue<pair<int,int>> temp;
        while(q.size()){
            auto cur = q.front(); q.pop();
            for(int i = 0; i < 4; i++){
                int ny = cur.first + dy[i];
                int nx = cur.second + dx[i];
                if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue;
                visited[ny][nx] = cnt;
                if(a[ny][nx] != '0'){
                    a[ny][nx] = '0';
                    temp.push({ny,nx});
                }
                else{
                    q.push({ny,nx});
                }
            }
        }
        q = temp;
    }    
    cout << visited[y2][x2] << '\n';
}