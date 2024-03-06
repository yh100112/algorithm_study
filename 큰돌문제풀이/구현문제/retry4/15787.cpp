#include<bits/stdc++.h>
using namespace std;
int n, m, a, b, c, train[100004], cnt;

int main(){
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        if (a <= 2) cin >> c;
        if (a == 1) {
            train[b] |= (1 << c);
        }
        else if (a == 2) {
            train[b] &= ~(1 << c);
        }
        else if (a == 3) {
            train[b] = (train[b] << 1);
            train[b] &= ~(1 << 21);
        }
        else if (a == 4) {
            train[b] = (train[b] >> 1);
            train[b] &= ~(1 << 0);
        }
    }

    vector<int> v(1 << 21); 
    for (int i = 1; i <= n; ++i) {
        if (!v[train[i]])
            cnt++;
        v[train[i]] = 1;
    }
    cout << cnt << "\n";
}