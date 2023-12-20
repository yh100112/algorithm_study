#include<bits/stdc++.h>
using namespace std;
#define time abc
const int INF = 987654321;
int n, m, b, a[504][504], time = INF, height = -INF;

// b: 인벤토리에 있는 블록의 개수
int main(){
    cin >> n >> m >> b;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    for(int h = 0; h <= 256; h++){
        int ese = 0;
        int fill = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] > h) ese += (a[i][j] - h);
                else fill += (h - a[i][j]);
            }
        }

        if(ese + b >= fill){
            if(time >= ese * 2 + fill){
                time = ese * 2 + fill;
                height = h;
            }
        }
    }
    cout << time << ' ' << height << '\n';
}