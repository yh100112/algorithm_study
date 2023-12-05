#include<bits/stdc++.h>
using namespace std;
int n, m, a, b, c, arr[100004], cnt;

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        if(a <= 2) cin >> c;

        if(a == 1){
            arr[b] |= (int)pow(2, c - 1);
        }
        else if(a == 2){
            arr[b] &= ~(int)pow(2, c - 1);
        }
        else if(a == 3){
            arr[b] = (arr[b] << 1);
            arr[b] &= ~(int)pow(2,20);
        }
        else if(a == 4){
            arr[b] = (arr[b] >> 1);
        }
    }

    vector<bool> chk(1 << 20, false);
    for(int i = 1; i <= n; i++){
        if(!chk[arr[i]]){
            cnt++;
            chk[arr[i]] = true;
        }
    }
    cout << cnt << '\n';
}