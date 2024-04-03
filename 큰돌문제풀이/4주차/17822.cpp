#include<bits/stdc++.h>
using namespace std;
int n, m, t, ret;
vector<vector<int>> a;
struct A {
    int x, d, k; // x의 배수인 원판을 d 방향으로 k칸 회전
};
vector<A> v;

void spin(int x, int d, int k) {
    for (int i = 0; i < n; i++) {
        if ((i + 1) % x != 0) continue;
        if (d == 0) rotate(a[i].rbegin(), a[i].rbegin() + k, a[i].rend()); // 시계
        else rotate(a[i].begin(), a[i].begin() + k, a[i].end()); // 반시계
    }
}

bool check() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j]) return true;
    return false;
}

bool be_closed_erase() {
    bool check = false;
    vector<vector<int>> temp = a;
    for (int i = 0; i < n; i++) {
        int prev = temp[i][0];
        int cur;
        int start = prev;
        for (int j = 1; j < m; j++) { // 같은 원 내에서 이웃한 수
            cur = temp[i][j];
            if (prev == cur) {
                temp[i][j] = 0;
                temp[i][j - 1] = 0;
                check = true;
            }
            prev = cur;
        }
        if (temp[i][temp[i].size() - 1] == start) {
            temp[i][0] = 0;
            temp[i][temp[i].size() - 1] = 0;
        }
    }

    vector<vector<int>> temp2 = a;
    for (int i = 0; i < m; i++) {
        int prev = temp2[0][i];
        int cur;
        for (int j = 1; j < n; j++) { // 서로 다른 원에서의 인접한 위치 ( 같은 인덱스 )
            cur = temp2[j][i];
            if (prev == cur) {
                temp2[j][i] = 0;
                temp2[j - 1][i] = 0;
                check = true;
            }
            prev = cur;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (temp[i][j] == 0 || temp2[i][j] == 0)
                a[i][j] = 0;
        }
    }
    return check;
}

int main() {
    cin >> n >> m >> t; // m : 원판에 적힌 수 개수
    a.resize(n);
    for (int i = 0; i < n; i++) {
        a[i].resize(m);
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    }

    for (int i = 0; i < t; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({a,b,c});
    }

    for (auto i : v) {
        int x = i.x;
        int d = i.d;
        int k = i.k;

        spin(x, d, k);
        if (check()) {
            if (be_closed_erase() == false) {
                for (int i = 0; i < n; i++) {
                    int average = accumulate(a[i].begin(), a[i].end(), 0) / a[i].size();
                    for (int j = 0; j < m; j++) {
                        if (a[i][j] > average) a[i][j]--;
                        else if (a[i][j] < average) a[i][j]++;
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ret += a[i][j];
        }
    }
    cout << ret << "\n";
}