#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
#define x1 aaaa
#define y1 aaa
int n, m, x1, y1, x2, y2, visited[304][304], cnt = 1;
char a[304][304];
queue<pair<int,int>> q;

int main(){
    cin >> n >> m;
    cin >> y1 >> x1 >> y2 >> x2;
    y1--, x1--, y2--, x2--;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];

    visited[y1][x1] = 1;
    q.push({y1,x1}); 

    while(a[y2][x2] != '0'){
        queue<pair<int,int>> temp;
        while(q.size()){
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue;
                visited[ny][nx] = cnt;
                if(a[ny][nx] == '0'){
                    q.push({ny,nx});
                }
                else{
                    temp.push({ny,nx});
                    a[ny][nx] = '0';
                }
            }
        }
        q = temp;
        cnt++;
    }
    cout << visited[y2][x2] << '\n';
}