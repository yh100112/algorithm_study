#include<bits/stdc++.h>
using namespace std;
#define Y first
#define X second
int n,m;
char arr[104][104];
int visited[104][104];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int main(){
   cin >> n >> m; 
   for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
   }

   queue<pair<int,int>> Q;
   Q.push({0,0});
   visited[0][0] = 1;

   while(!Q.empty()){
        pair<int,int> cur = Q.front(); Q.pop();
        for(int i = 0; i < 4; i++){
            int ny = cur.Y + dy[i];
            int nx = cur.X + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(arr[ny][nx] == '0' || visited[ny][nx] > 0) continue;
            visited[ny][nx] = visited[cur.Y][cur.X] + 1;
            Q.push({ny,nx});
        }
   }
   cout << visited[n-1][m-1];

}