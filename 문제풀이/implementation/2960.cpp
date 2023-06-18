// #include<bits/stdc++.h>
// using namespace std;
// int n,k;
// vector<int> arr;

// int main(){
//     cin >> n >> k;
//     for(int i = 2; i <= n; i++){
//         arr.push_back(i);
//     }
//     int cnt = 0;
//     int mn = arr.front();
//     while(true){
//         for(int i = 0; i < arr.size(); i++){
//             if(arr[i] % mn == 0){
//                 int tmp = arr[i];
//                 arr[i] = -1;
//                 cnt++;
//                 if(cnt == k){
//                     cout << tmp << "\n";
//                     return 0;
//                 }
//             }
//         }
//         mn = mn + 1;
//     }
// }

// 내가 생각하지 못한 다른 풀이
#include<bits/stdc++.h>
using namespace std;
int n, k, cnt, c[1001], ans;

int main(){
    cin >> n >> k;
    for(int i = 2; i <= n; i++){
        for(int j = i; j <= n; j += i) {
            if(c[j] == 0) { cnt++; c[j] = 1; }
            if(cnt == k) { ans = j; break; }
        }
        if(cnt == k) break;
    }
    cout << ans << "\n";
}











