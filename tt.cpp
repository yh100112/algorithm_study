#include<bits/stdc++.h>
using namespace std;
int n, ret;
int isused[40], isused2[40], isused3[40];

void go(int here) {
    if (here == n) {
        ret++;
        return;
    }
    
    for(int x = 0; x < n; x++) {
        if (isused[x] || isused2[x + here] || isused3[x - here + n - 1]) continue;
        isused[x] = 1;
        isused2[x + here] = 1;
        isused3[x - here + n - 1] = 1;
        go(here + 1);
        isused[x] = 0;
        isused2[x + here] = 0;
        isused3[x - here + n - 1] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    go(0);
    cout << ret << "\n";
}