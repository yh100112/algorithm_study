
/*
배열을 시계방향 or 반시계방향으로 회전해야 하는 로직을 구축해야 한다면?
예시)
배열 {1,2,3,4,5,6}을
시계방향으로 한 칸 움직이면  -> {6,1,2,3,4,5}
반시계방향으로 한 칸 움직이면 -> {2,3,4,5,6,1}
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    // 한칸씩 왼쪽으로
    vector<int> v = {1, 2, 3, 4, 5, 6};
    rotate(v.begin(), v.begin() + 1, v.end()); // 회전할 구간 : [first,last),  (first, 몇 칸 이동할지, last)
    for (int i : v)
        cout << i << ' '; // 2 3 4 5 6 1
    cout << endl;

    // 2칸씩 왼쪽으로
    vector<int> vv = {1, 2, 3, 4, 5, 6};
    rotate(vv.begin(), vv.begin() + 2, vv.end());
    for (int i : vv)
        cout << i << ' '; // 3 4 5 6 1 2
    cout << endl;

    // 한칸씩 오른쪽으로
    vector<int> vvv = {1, 2, 3, 4, 5, 6};
    rotate(vvv.rbegin(), vvv.rbegin() + 1, vvv.rend()); // rbegin() : 배열의 마지막번째, rend()배열의 시작 전의 위치 반환
    for (int i : vvv)
        cout << i << ' ';
}