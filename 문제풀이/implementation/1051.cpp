#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[54][54];

int main(){
    cin >> n >> m;
    int i,j;
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            scanf("%1d", &arr[i][j]);
        }
    }
    int mx = -1;
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            int k = 0;
            int cur = arr[i][j];
            while(true){
                if(j + k > m-1 || i + k > n-1 || k > min(n,m) - 1) 
                    break; 
                if(arr[i][j+k] == cur && arr[i+k][j] == cur && arr[i + k][j + k] == cur){
                    mx = max(mx, (k+1) * (k+1));
                }
                k++;
            }
        }
    }
    cout << mx << "\n";
}