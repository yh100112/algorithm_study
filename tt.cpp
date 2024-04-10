#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;

int main() {
    while(cin >> n) {
        ll num = 1;
        int cnt = 1;
        while(true) {
            if (num % n == 0) {
                cout << cnt << "\n";
                break;
            }
            num = (num * 10 + 1) % n;
            cnt++;
        }
    }
}