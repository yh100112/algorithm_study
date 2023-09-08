// #include<bits/stdc++.h>
// using namespace std;
// string str;
// int arr[10];

// int main(){
//     cin >> str;
//     int a = stoi(str);
//     for(int i = 0; i < str.length(); i++){
//         int num = a / pow(10, str.length() - (i+1));
//         a = a % (int)pow(10, str.length() - (i+1));
//         arr[num]++;
//     }
//     arr[9] += arr[6];
//     arr[6] = 0;
//     int flag = 0;
//     int cnt = 0;
//     while(true){
//         for(int i = 0; i < 10; i++){
//             if(arr[i] > 0) {
//                 flag = 1; // 값이 남아있다면 체크
//                 if(i == 9){
//                     if(arr[i] >= 2) arr[i] -= 2;
//                     else arr[i]--;
//                 }
//                 else {
//                     arr[i]--;
//                 }
//             }
//         }
//         if(flag == 0){
//             cout << cnt << "\n";
//             return 0;
//         }
//         cnt++;
//         flag = 0;
//     }
// }

// 다른 풀이
#include<bits/stdc++.h>
using namespace std;
int arr[10];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    while(n > 0) {
       arr[n % 10]++;
       n /= 10; 
    }

    int ret = 1; // 기본 세트수
    for(int i = 0; i < 10; i++){
        if(i == 6 || i == 9)
            continue;
        ret = max(ret, arr[i]);
    }

    ret = max(ret, (arr[6] + arr[9] + 1) / 2);
    cout << ret << "\n";
}