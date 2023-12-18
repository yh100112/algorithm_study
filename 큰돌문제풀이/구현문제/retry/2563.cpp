#include<bits/stdc++.h>
using namespace std;
int arr[102][102], a, b, ret, n;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        for(int k = b; k < b + 10; k++){
            for(int j = a; j < a + 10; j++){
                arr[k][j] = 1;
            }
        }
    }
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            if(arr[i][j]) ret++;
        }
    }
    cout << ret << '\n';
}