#include<bits/stdc++.h>
using namespace std;
string str;
int arr[10];

int main(){
    cin >> str;
    int a = stoi(str);
    for(int i = 0; i < str.length(); i++){
        int num = a / pow(10, str.length() - (i+1));
        a = a % (int)pow(10, str.length() - (i+1));
        arr[num]++;
    }
    arr[9] += arr[6];
    arr[6] = 0;
    int flag = 0;
    int cnt = 0;
    while(true){
        for(int i = 0; i < 10; i++){
            if(arr[i] > 0) {
                flag = 1; // 값이 남아있다면 체크
                if(i == 9){
                    if(arr[i] >= 2) arr[i] -= 2;
                    else arr[i]--;
                }
                else {
                    arr[i]--;
                }
            }
        }
        if(flag == 0){
            cout << cnt << "\n";
            return 0;
        }
        cnt++;
        flag = 0;
    }
}