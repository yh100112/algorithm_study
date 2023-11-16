#include<bits/stdc++.h>
using namespace std;
int n, ret = -987654321;

struct Board{
    int a[24][24];
    void rotate90_(){
        int temp[24][24];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                temp[i][j] = a[n - j - 1][i];
            }
        }
        memcpy(a, temp, sizeof(temp));
    }
    void move_(){
        int temp[24][24];
        for(int i = 0; i < n; i++){
            int flag = 0, idx = -1;
            for(int j = 0; j < n; j++){
                if(!a[i][j]) continue;
                if(flag && temp[i][idx] == a[i][j]) temp[i][idx] *= 2, flag = 0;
                else temp[i][++idx] = a[i][j], flag = 1;
            }
            idx++;
            for(; idx < n; idx++) temp[i][idx] = 0;
        }
        memcpy(a, temp, sizeof(temp));
    }
    void get_max(){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                ret = max(ret, a[i][j]);
            }
        }
    }
};

void go(Board c, int cnt){
    if(cnt == 5){
        c.get_max();
        return;
    }

    for(int i = 0; i < 5; i++){
        Board d = c;
        d.move_();
        go(d, cnt + 1);
        c.rotate90_();
    }
}

int main(){
    cin >> n;
    Board c;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> c.a[i][j];
    
    go(c, 0);
    cout << ret << '\n';
}