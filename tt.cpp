#include<bits/stdc++.h>
using namespace std;
long long n, a[100004], visited[100004], ret, s, e;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    while(e < n) {
        if (visited[a[e]]) {
            ret += (e - s);
            visited[a[s++]]--;
        }
        else {
            visited[a[e++]]++;
        }
    }
    ret += (e - s) * (e - s + 1) / 2;
    cout << ret << "\n";
}