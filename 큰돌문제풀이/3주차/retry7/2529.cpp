#include<bits/stdc++.h>
using namespace std;
int k, used[10];
char c[10];
vector<string> v;

bool check(int a, int b, char c) {
    if (c == '>') return a > b;
    if (c == '<') return a < b;
}

void go(int idx, string str) {
    if(idx == k + 1) {
        v.push_back(str);
        return;
    }
    for (int i = 0; i < 10; i++) {
        if (idx == 0 || (used[i] == 0 && check(str[idx - 1] - '0', i, c[idx - 1]))) {
            used[i] = 1;
            go(idx + 1, str + to_string(i));
            used[i] = 0;
        }
    }
}

int main() {
    cin >> k;
    for (int i = 0; i < k; i++)
        cin >> c[i];
    go(0, "");

    sort(v.begin(), v.end());
    cout << v[v.size() - 1] << "\n";
    cout << v.front() << "\n";
}