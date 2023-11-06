#include<bits/stdc++.h>
using namespace std;
int n, ret;
int a[24][24];

void _rotate90(){
    int temp[24][24];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            temp[i][j] = a[n - j - 1][i];
        }
    }
    memcpy(a, temp, sizeof(temp));
}
void _move(int temp[][n]){
    for(int i = 0; i < n; i++){
        int c = -1, d = 0;
        for(int j = 0; j < n; j++){
            if(a[i][j] == 0) continue;
            if(d && a[i][j] == temp[i][c]) temp[i][c] *= 2, d = 0;
            else temp[i][++c] = a[i][j], d = 1;
        }
        c++;
        for(; c < n; c++) temp[i][c] = 0;
    }
}
void get_max(int temp[][n]){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            ret = max(ret, temp[i][j]);
}

void go(int temp[][n], int here){
    if(here == 5){
        get_max(temp);
        return;
    }
    for(int i = 0; i < 4; i++){
        int t[24][24];
        memcpy(t, temp, sizeof(temp));
        _move(t); // 복사본을 한쪽으로 밈
        go(t, here + 1);
        _rotate90(); // 원본을 회전 -> 복사본인 d로 무브작업을 했으므로 원본은 그대로 유지되어 있음
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];
    go(a, 0);
    cout << ret << '\n';
}