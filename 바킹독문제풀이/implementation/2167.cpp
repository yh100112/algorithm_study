#include<bits/stdc++.h>
using namespace std;
int n,m,k,i,j,x,y;
int arr[304][304];

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    cin >> k;
    for(int c = 0; c < k; c++){
        cin >> i >> j >> x >> y;
        int ret = 0;
        for(int a = i-1; a <= x-1; a++){
            for(int b = j-1; b <= y-1; b++){
                ret += arr[a][b];
            }
        }
        cout << ret << "\n";
    }
}