#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int arr[3][102];
int st, en;
int sum[102];
int ans;

int main(){
    cin >> a >> b >> c;
    for(int i = 0; i < 3; i++){
        st = 0;
        en = 0;
        cin >> st >> en;
        for(int j = st; j < en; j++){
            arr[i][j] = 1;
        }
    }
    for(int i = 1; i < 101; i++){
        if (arr[0][i]) sum[i]++;
        if (arr[1][i]) sum[i]++;
        if (arr[2][i]) sum[i]++; 

        int pay = 0;
        if (sum[i] == 1) pay = a * 1;
        else if (sum[i] == 2) pay = b * 2;
        else if (sum[i] == 3) pay = c * 3;
        ans += pay; 
    }
    cout << ans << "\n";
}