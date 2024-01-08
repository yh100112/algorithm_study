#include<bits/stdc++.h>
using namespace std;
int n, arr[104][104], ret, a, b;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        for(int j = b; j < b + 10; j++)
            for(int k = a; k < a + 10; k++)
                arr[j][k] = 1;
    }

    for(int i = 0; i <= 100; i++){
        for(int j = 0; j <= 100; j++){
            if(arr[i][j]) ret++;
        }
    }
    cout << ret << '\n';
}