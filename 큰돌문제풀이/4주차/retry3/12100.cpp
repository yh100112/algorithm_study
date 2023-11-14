#include<bits/stdc++.h>
using namespace std;
const int INF = -987654321;
int n, ret = INF;

struct Board{
    int a[24][24];
    void move_(){
        int temp[24][24];
        for(int i = 0; i < n; i++){
            int idx = -1, flag = 1;
            for(int j = 0; j < n; j++){
                if(!a[i][j]) continue; 
                if(!flag && temp[i][idx] == a[i][j]) temp[i][idx] *= 2, flag = 1;
                else temp[i][++idx] = a[i][j], flag = 0;
            }
            idx++;
            for(; idx < n; idx++) temp[i][idx] = 0;
        }
        memcpy(a, temp, sizeof(temp));
    }
    void rotate90(){
        int temp[24][24];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                temp[i][j] = a[n - j - 1][i];
        memcpy(a, temp, sizeof(temp));
    }
    void get_max(){
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                ret = max(ret, a[i][j]);
    }
};

void go(Board c, int cnt){
    if(cnt == 5){
        c.get_max();
        return;
    }

    for(int i = 0; i < 4; i++){
        Board d = c;
        d.move_();
        go(d, cnt + 1);
        c.rotate90();
    }
}

int main(){
    Board c;
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> c.a[i][j];
    go(c, 0);
    cout << ret << '\n';
}