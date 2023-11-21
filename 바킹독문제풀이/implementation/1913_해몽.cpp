#include<bits/stdc++.h>
using namespace std;
int arr[1001][1001];
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};
int n, k; 

int main(){
    cin >> n >> k;
    int s = n * n;
    int y = -1, x = 0, dir = 0;
    int ansy = 0, ansx = 0;
    function<bool(int,int)> inrange = [&](int y, int x) -> bool { 
        return 0 <= y && y < n && 0 <= x && x < n; 
    };
    while(s > 0){
        int qy = y + dy[dir];
        int qx = x + dx[dir];
        if(!inrange(qy, qx) || arr[qy][qx] != 0) { // 범위를 벗어나거나 숫자가 있는 경우 방향 바꿈 -> 아 완전탐색과 비슷한 해법이구나!!
            dir = (dir + 1) % 4;
            continue;
        }
        y = qy; x = qx;
        arr[y][x] = s;
        if(s == k){
            ansy = y + 1;
            ansx = x + 1;
        }
        s--;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << ansy << ' ' << ansx;

    return 0;
}