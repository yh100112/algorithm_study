#include<bits/stdc++.h>
using namespace std;
int k;
char a[10], visited[10];
vector<string> ret;

bool comp(int num1, int num2, char arith) {
    if (arith == '>') return num1 > num2;
    if (arith == '<') return num1 < num2;
}

void go(int idx, string s) {
    if (idx == k + 1) {
        ret.push_back(s);
        return;
    }

    for (int i = 0; i < 10; ++i) {
        if (visited[i]) continue;
        if (idx == 0 || comp(s[idx - 1] - '0', i, a[idx - 1]) == true) {
            s += to_string(i);
            visited[i] = 1;
            go(idx + 1, s);
            s.erase(s.end() - 1);
            visited[i] = 0;
        }
    }
}

int main() {
    cin >> k;
    for (int i = 0; i < k; ++i)
        cin >> a[i];

    go(0, "");
    sort(ret.begin(), ret.end());
    cout << ret[ret.size() - 1] << "\n";
    cout << ret[0] << "\n";
}