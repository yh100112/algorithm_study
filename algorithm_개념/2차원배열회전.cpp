#include <bits/stdc++.h>
using namespace std;
const int n = 3;

// 2차원 배열의 좌우 길이가 같은 경우
void rotate_right_90(vector<vector<int>> &key)
{
    vector<vector<int>> temp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp[i][j] = key[n - j - 1][i];
        }
    }
    key = temp;
    return;
}
// i, j = n - j - 1, i라고 외우기

int main()
{
    vector<vector<int>> a = {
        {1, 2, 3},
        {5, 6, 7},
        {9, 10, 11},
    };
    rotate_right_90(a);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}