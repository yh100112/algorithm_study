#include<bits/stdc++.h>
using namespace std;
int n,x,y;
int arr[104][104];
int cnt;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        for(int j = x; j < x+10; j++){
            for(int k = y; k < y+10; k++){
                if(arr[j][k] == 0) {
                    arr[j][k] = 1; 
                    cnt++;
                }
            }
        }
    }
    cout << cnt << endl;
}