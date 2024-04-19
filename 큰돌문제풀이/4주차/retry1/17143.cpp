#include<bits/stdc++.h>
using namespace std;
#define max_n 100
const int dy[] = {-1,1,0,0};
const int dx[] = {0,0,1,-1};
struct Shark {
    int y, x, s, dir, z, death;
}a[max_n * max_n];
int shark[max_n][max_n], R, C, M, ret, temp[max_n][max_n];

int main() {
    cin >> R >> C >> M;
    for (int i = 1; i <= M; i++) {
        cin >> a[i].y >> a[i].x >> a[i].s >> a[i].dir >> a[i].z;
        a[i].y--, a[i].x--, a[i].dir--;

        if (a[i].dir <= 1)
            a[i].s %= (2 * (R - 1));
        else
            a[i].s %= (2 * (C - 1));
        
        shark[a[i].y][a[i].x] = i; // 상어 번호
    }

    for (int t = 0; t < C; t++) {
        // 상어 포획
        for (int y = 0; y < R; y++) {
            if (shark[y][t]) {
                a[shark[y][t]].death = 1;
                ret += a[shark[y][t]].z;
                break;
            }
        }
        memset(temp, 0, sizeof(temp));

        // 상어 이동
        for (int i = 1; i <= M; i++) {
            if (a[i].death) continue;
            int y = a[i].y;
            int x = a[i].x;
            int s = a[i].s;
            int d = a[i].dir;
            int ny, nx;

            // 최대 2번 도는 반복문
            // 2번 더 도는 경우 : 중앙에 있어서 왼쪽 오른쪽 벽을 다 치고 방향이 2번 바뀌는 경우
            // 1번 더 도는 경우 : 벽을 한번 치고 방향이 1번 바뀌는 경우
            // 바로 탈출하는 경우 : 벽을 닿지 않는 경우
            while(true) {
                ny = y + s * dy[d];
                nx = x + s * dx[d];
                if (ny >= 0 && ny < R && nx >= 0 && nx < C) break; // 범위 안에 있으면

                // 범위를 넘어가는 경우 ( 벽에 부딪히는 경우 )
                if (d <= 1) { // 상하
                    if (ny < 0) {
                        s -= y;
                        y = 0;
                    }
                    else {
                        s -= R - 1 - y;
                        y = R - 1;
                    }
                }
                else { // 우좌
                    if (nx < 0) {
                        s -= x;
                        x = 0;
                    }
                    else {
                        s -= C - 1 - x;
                        x = C - 1;
                    }
                }
                d ^= 1;
            }
            if (temp[ny][nx]) {
                if (a[temp[ny][nx]].z < a[i].z) {
                    a[temp[ny][nx]].death = 1;
                    temp[ny][nx] = i;
                }
                else
                    a[i].death = 1;
            }
            else
                temp[ny][nx] = i;
            
            a[i].y = ny;
            a[i].x = nx;
            a[i].dir = d;
        }
        memcpy(shark, temp, sizeof(temp));
    }
    cout << ret << "\n";
}