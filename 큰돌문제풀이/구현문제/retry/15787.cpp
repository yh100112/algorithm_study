#include<bits/stdc++.h>
using namespace std;
int n, m, a, b, c, ret; 
int train[100004];

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        if(a <= 2) cin >> c;

        if(a == 1){
            train[b] |= (int)pow(2, c);
        }
        else if(a == 2){
            train[b] &= ~(int)pow(2, c);
        }
        else if(a == 3){
            train[b] = (train[b] << 1);
            train[b] &= ~(int)pow(2,21);
        }
        else if(a == 4){
            train[b] = (train[b] >> 1);
            train[b] &= ~(int)pow(2,0);
        }
    }

    vector<bool> visited(1 << 21, false);
    for(int i = 1; i <= n; i++){
        if(!visited[train[i]]){
            visited[train[i]] = true;
            ++ret;
        }
    }

    cout << ret << '\n';
}