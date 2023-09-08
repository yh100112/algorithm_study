#include<bits/stdc++.h>
using namespace std;
int n, k, cnt;
int a[200002], visited[200002]; 
const int dx[] = {-1,1,2};

int main(){
    cin >> n >> k;
    a[k] = 1; // 동생 위치

    queue<int> q;
    q.push(n);
    visited[n] = 1;
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        if(a[cur] == 1)
            break;
        for(int i = 0; i < 3; i++){
            int nx;
            if(dx[i] == 2) nx = cur * dx[i];
            else nx = cur + dx[i];
            if(visited[nx]) continue;
            visited[nx] = visited[cur] + 1;
            q.push(nx);
        }
    }
    cout << visited[k] - 1 << "\n";
}