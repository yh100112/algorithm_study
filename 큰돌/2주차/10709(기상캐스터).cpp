#include<bits/stdc++.h>
using namespace std;
char arr[102][102];
int ret[102][102];
int h,w;
int main(){
    cin >> h >> w;
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            cin >> arr[i][j];

    int flag = 0;
    int cnt = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(arr[i][j] == 'c'){
                ret[i][j] = 0;
                flag = 1;
                cnt = 0;
            }
            else {
                if (flag == 0) ret[i][j] = -1;
                else {
                    cnt++;
                    ret[i][j] = cnt;
                }
            }
        }
        cnt = 0;
        flag = 0;
    }

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cout << ret[i][j] << " ";
        }
        cout << "\n";
    }
}