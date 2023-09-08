#include<bits/stdc++.h>
using namespace std;
int n, cnt;
int arr[26];
string a;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        arr[a[0] - 'a']++;
    }
    for(int i = 0; i < 26; i++){
        if (arr[i] >= 5) {
            cnt++;
            cout << (char)('a' + i);
        }
    }
    if (cnt == 0) cout << "PREDAJA" << "\n";
}