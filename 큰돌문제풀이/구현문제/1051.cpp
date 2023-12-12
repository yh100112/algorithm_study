#include<bits/stdc++.h>
using namespace std;
const int dy[] = {0,1,1};
const int dx[] = {1,1,0};
int n, m, a[54][54], shorter, ret = 1;
string s;

void check(int y, int x){
    for(int len = 0; len < shorter; len++){
        bool flag = true;
        for(int dir = 0; dir < 3; dir++){
            int add_y = dy[dir];
            int add_x = dx[dir];
            if(add_y != 0) add_y += len;
            if(add_x != 0) add_x += len;
            int ny = y + add_y;
            int nx = x + add_x;
            if(ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] != a[y][x]) {
                flag = false;
                break;
            }
        }
        if(flag) ret = max((len + 2) * (len + 2), ret); 
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < m; j++)
            a[i][j] = s[j] - '0';
    }

    shorter = min(n, m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            check(i,j);
        }
    }
    cout << ret << '\n';
}