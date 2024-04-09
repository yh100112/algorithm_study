#include<bits/stdc++.h>
using namespace std;
int n, num;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        long long two = 0;
        long long five = 0;
        for (int i = 2; i <= num; i *= 2)
            two += (num / i);
        for (int i = 5; i <= num; i *= 5)
            five += (num / i);
        cout << min(two, five) << "\n";
    }
}