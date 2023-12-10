#include<bits/stdc++.h>
using namespace std;
int a[10], six_nine, mx = -987654321, ret;
string n;

int main(){
    cin >> n; 
    for(int i = 0; i < n.length(); i++){
        a[n[i] - '0']++;
    }
    for(int i = 0; i < 10; i++){
        if(i == 6 || i == 9) continue;
        mx = max(a[i], mx);
    }

    six_nine = (a[6] + a[9]) % 2 == 0 ? (a[6] + a[9]) / 2 : (a[6] + a[9]) / 2 + 1; // 6과 9 필요 세트수
    ret = max(six_nine, mx);
    cout << ret << '\n';
}