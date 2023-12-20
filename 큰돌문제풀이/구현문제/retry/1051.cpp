#include<bits/stdc++.h>
using namespace std;
const int INF = -987654321;
int n, m, a[52][52], len, area, ret = INF;
string s;

bool check(int y, int x){
    if(a[y + len][x] != a[y][x]) return false;
    if(a[y][x + len] != a[y][x]) return false;
    if(a[y + len][x + len] != a[y][x]) return false;
    return true;
}

void go(int y, int x){
    area = 1;
    len = 1;
    while(y + len < n && x + len < m){
        if(check(y,x))
            area = (len + 1) * (len + 1);
        len++;
    }
    ret = max(ret, area);
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < s.length(); j++)
            a[i][j] = s[j] - '0';
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            go(i, j);
        }
    }
    cout << ret << '\n';
}