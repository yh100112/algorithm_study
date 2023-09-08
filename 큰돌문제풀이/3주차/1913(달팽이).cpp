#include<bits/stdc++.h>
using namespace std;
int n, findNum, y, x, cnt, dir;
int a[1004][1004];
void print(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << "\n";
    }
}
int main(){
    cin >> n >> findNum;
    y = n / 2;
    x = n / 2;
    a[y][x] = 1;
    cnt = 1;
    int flag = 0;
    int len = 1;
    while(cnt < n*n){
        if(dir == 0){
            for(int i = 0; i < len; i++) {
                if(cnt == n*n) break;
                a[--y][x] = ++cnt;
            }
            flag++;
        }
        else if(dir == 1){
            for(int i = 0; i < len; i++){
                if(cnt == n*n) break;
                a[y][++x] = ++cnt;
            }
            flag++;
        }
        else if(dir == 2){
            for(int i = 0; i < len; i++){
                if(cnt == n*n) break;
                a[++y][x] = ++cnt;
            }
            flag++;
        }
        else if(dir == 3){
            for(int i = 0; i < len; i++){
                if(cnt == n*n) break;
                a[y][--x] = ++cnt;
            }
            flag++;
        }
        dir = (dir + 1) % 4;
        if(flag % 2 == 0) len++;
    } 
    print();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] == findNum){
                cout << i+1 << " " << j+1 << "\n";
                return 0;
            }
        }
    }
}