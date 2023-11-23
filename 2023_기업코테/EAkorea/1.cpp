#include <iostream>
#include <algorithm>

using namespace std;

int minBoxes(int n) {
    // 3과 5의 최소 공배수인 15를 이용하여 최소 상자 개수를 계산합니다.
    for (int i = 0; i <= n / 3; ++i) {
        int remainder = n - 3 * i;
        if (remainder % 5 == 0) {
            return i + remainder / 5;
        }
    }

    // 3과 5의 조합으로 모든 옷을 담을 수 없는 경우
    return -1;
}

int main() {
    int n;
    cin >> n;
    int result = minBoxes(n);
    cout << result << '\n';

    return 0;
}
