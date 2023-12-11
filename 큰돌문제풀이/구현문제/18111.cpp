#include<bits/stdc++.h>
using namespace std;
#define fill aaa
const int INF = 987654321;
int n, m, b, a[504][504], ese, fill, t = INF, height = -INF;

int main(){
    cin >> n >> m >> b;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    
    for(int h = 0; h <= 256; h++){
        ese = fill = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] > h) ese += (a[i][j] - h); // 지울 블록
                else fill += (h - a[i][j]); // 채울 블록
            }
        }

        if(ese + b >= fill){
            if(t >= ese * 2 + fill){
                t = ese * 2 + fill;
                height = h;
            }
        }
    }
    cout << t << ' ' << height << '\n';
}