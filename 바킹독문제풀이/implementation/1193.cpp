// 내 풀이
// #include<bits/stdc++.h>
// using namespace std;
// int X;
// int cnt, cnt_sum;

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cin >> X;
//     while(true){
//         if(cnt_sum >= X) break;
//         cnt++;
//         cnt_sum += cnt;
//     }
//     if(cnt & 1) {
//         int x = cnt, y = 1;
//         int st = cnt_sum - cnt + 1;
//         while(true){
//             if(st == X) break;
//             st++;
//             x--; 
//             y++;
//         }
//         cout << x <<"/" << y << "\n";
//     }
//     else {
//         int x = 1, y = cnt;
//         int st = cnt_sum - cnt + 1;
//         while(true){
//             if(st == X) break;
//             st++;
//             x++;
//             y--;
//         }
//         cout << x << "/" << y << "\n";
//     }
// }

#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    int i = 1;
    while(N > i) {
        N -= i;
        i++;
    }

    if(i % 2 == 1) {
        cout << i + 1 - N << "/" << N << "\n";
    }
    else {
        cout << N << "/" << i + 1 - N << "\n";
    }
}