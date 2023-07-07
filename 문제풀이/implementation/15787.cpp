#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[100004];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m; // 기차의 개수 n, 명령의 개수 m
    for(int i = 0; i < m; i++){
        int a,b,c;
        cin >> a >> b;
        if(a <= 2) cin >> c;
        if(a == 1){
            arr[b] |= int(pow(2,c));
        }
        else if(a == 2){
            arr[b] &= int(pow(2,c));
        }
        else if(a == 3){
            arr[b] = (arr[b] << 1);
            arr[b] &= ((1<<21) - 1);
        }
        else if(a == 4){
            arr[b] = (arr[i] >> 1);
            arr[b] &= (~1);
        }
    }

    vector<bool> chk(1 << 21, false);
    int ret = 0;
    for(int i = 1; i <= n; i++){
        if(chk[arr[i]] == false) {
            ret++;
            chk[arr[i]] = true;
        }
    }
    cout << ret;
}