#include<bits/stdc++.h>
using namespace std;
long long s;

int main() {
    cin >> s;

    long long cnt = 1;
    long long sum = 0;
    while(true) {
        sum += cnt++;
        if (sum > s) break;
    }
    if (sum == s) cout << cnt - 1 << "\n";
    else cout << cnt - 2 << "\n";
}