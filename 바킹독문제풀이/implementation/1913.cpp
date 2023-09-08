#include<bits/stdc++.h>
using namespace std;
int n, m;
int i,j;
int ret_x, ret_y;
int arr[1004][1004];
int dx[4] = {0,1,0,-1}; // 우 하 좌 상
int dy[4] = {1,0,-1,0};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    i = n/2; j = n/2;
    arr[i][j] = 1;
    int ni = dx[3]; int nj = dy[3]; // 첫 시작값 : 상 ( -1,0 )
    int num = 2; int cnt = 1;
    i += ni; j += nj;
    int idx = 0;
    arr[i][j] = num; // 2
    if (m == 1) {
        ret_x = n/2; ret_y = n/2;
    }
    else if (m == 2) {
        ret_x = i; ret_y = j;
    }
    ni = dx[(idx) % 4]; // 상 -> 우
    nj = dy[(idx) % 4];

    for(int a = 3; a <= n; a += 2) {
        while(true){
            num++; cnt++;
            i += ni; j += nj;
            arr[i][j] = num;
            if (num == m) {
                ret_x = i; ret_y = j;
            }
            if(num == a * a) {
                break;
            }
            if(cnt == a-1) {
                idx++;
                ni = dx[idx % 4]; // 상 -> 우 -> 하 - >좌
                nj = dy[idx % 4];
                cnt = 0;
            }
        }
        if (a != n) {
            num++; cnt = 1;
            i += ni; j += nj;
            arr[i][j] = num;
            if (num == m) {
                ret_x = i; ret_y = j;
            }
            idx++;
            ni = dx[idx % 4]; // 상 -> 우
            nj = dy[idx % 4];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << ret_x+1 << " " << ret_y+1 << "\n";
}