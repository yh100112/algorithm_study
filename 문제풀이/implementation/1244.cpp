#include<bits/stdc++.h>
using namespace std;
int n, m, a, b;
int arr[104];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b; // 성별, 스위치 번호
        if(a == 1) { // 남
            for(int j = 1; j <= n; j++){
                if(j % b == 0){
                    if(arr[j] == 1) arr[j] = 0;
                    else            arr[j] = 1;
                }
            }
        }
        else if(a == 2) { // 여
            int back = -1, front = -1;
            int cnt = 1;
            while(true){
                back = b - cnt;
                front = b + cnt;
                if(back < 1 || front > n) break;
                if(arr[back] != arr[front]) break;
                cnt++;
            }
            back += 1;
            front -= 1;
            for(int j = back; j <= front; j++){
                if(arr[j] == 1) arr[j] = 0;
                else            arr[j] = 1;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(i % 20 == 0) cout << arr[i] << "\n";
        else cout << arr[i] << " ";
    }
}