#include<bits/stdc++.h>
using namespace std;
int n, x, ret;
vector<int> v;

int main(){
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    cin >> x;
    sort(v.begin(), v.end());

    int l = 0;
    int r = n - 1;
    while (true) {
        if (l == r) break;
        if (v[l] + v[r] > x) {
            --r;
        }
        else if (v[l] + v[r] == x) {
            --r;
            ret++;
        }
        else {
            ++l;
        }
    }
    cout << ret << "\n";
}