#include<bits/stdc++.h>
using namespace std;
int n, l, a, b, ret;
vector<pair<int,int>> v;

int main() {
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end());

    int s = 0;
    int e = 0;
    for (int i = 0; i < n; i++) {
        if (e < v[i].first) { // 널판지 끝이 웅덩이 시작 위치보다 전인 경우
            int cnt = (v[i].second - v[i].first) / l;
            int remain = (v[i].second - v[i].first) % l;

            if (remain > 0)
                cnt++;
            
            s = v[i].first; // 널판지 시작 위치
            e = s + cnt * l; // 널판지 끝 위치
            ret += cnt;
        }
        else if(e < v[i].second) { // 널판지 끝 >= 웅덩이 시작 위치 and 널판지 끝 < 웅덩이 끝 위치
            int cnt = (v[i].second - e) / l;
            int remain = (v[i].second - e) % l;

            if (remain > 0)
                cnt++;
            
            e = e + cnt * l;
            ret += cnt;
        }
    }
    cout << ret << "\n";
}