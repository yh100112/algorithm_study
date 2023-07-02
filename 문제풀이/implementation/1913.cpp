#include<bits/stdc++.h>
using namespace std;
int n, m;
int i,j;
int arr[1004][1004];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    i = n/2; j = n/2;
    int num = 0;
    int cnt = 0;
    int k = 3;
    int idx = 3;
    int ni = dx[idx]; int nj = dy[idx]; // 첫 시작값 : 상 ( -1,0 )
    while(num <= n * n){
        num++; cnt++;
        arr[i][j] = num;
        cout << i << " " << j << " " << cnt << endl;
        if(cnt == k-1) {
            ni = dx[(idx + 1) % 4]; // 상 -> 우 -> 하 - >좌
            nj = dy[(idx + 1) % 4];
            cnt = 0;
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}