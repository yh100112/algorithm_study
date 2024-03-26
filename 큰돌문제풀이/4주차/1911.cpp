#include<bits/stdc++.h>
using namespace std;
int n, m, idx, ret, b;

int main() {
    cin >> n >> m;
    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end());

    // idx : 놓은 널판지의 끝
    // b : 새롭게 필요한 널판지 개수
    for (int i = 0; i < n; i++) {
        if(a[i].second <= idx) continue; // 널판지 끝보다 웅덩이 끝이 작을 때
        if(idx < a[i].first) { // 널판지 끝보다 웅덩이 시작이 클 때
            b = (a[i].second - a[i].first) / m + ((a[i].second - a[i].first) % m ? 1 : 0);
            idx = a[i].first + b * m;
        }
        else { // 널판지 끝이 웅덩이 시작 지점보다 클 때 ( 여기서는 널판지 끝이 웅덩이 끝보다는 작은 것만 옴 )
            b = (a[i].second - idx) / m + ((a[i].second - idx) % m ? 1 : 0);
            idx = idx + b * m;
        }
        ret += b;
    }
    cout << ret << "\n";
}