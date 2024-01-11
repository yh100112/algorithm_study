#include<bits/stdc++.h>
using namespace std;
int a,b,c,n,m, train[100004], cnt;

// train 맨 앞칸은 0010 -> 즉, 2^1부터 시작 ~ 2^20까지 끝. 2^21부터는 무효
int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        if(a <= 2) cin >> c;

        if(a == 1){
            train[b] |= (1 << c);
        }
        else if(a == 2){
            train[b] &= ~(1 << c);
        }
        else if(a == 3){
            train[b] = train[b] << 1;
            train[b] &= ~(1 << 21);
        }
        else{
            train[b] = train[b] >> 1;
            train[b] &= ~1;
        }
    }

    vector<int> visited(1 << 21, 0);
    for(int i = 1; i <= n; i++){
        if(visited[train[i]] == false){
            cnt++;
            visited[train[i]] = 1;
        }
    }
    cout << cnt << '\n';
}