#include<bits/stdc++.h>
using namespace std;
#define max_n 100
const int dy[] = {-1,1,0,0};
const int dx[] = {0,0,1,-1};
struct Shark {
    int y, x, s, dir, size, death;
}a[max_n * max_n]; // 상버별로 번호(idx)를 매겨서 저장
int shark[max_n][max_n], temp[max_n][max_n];
int R, C, M, ret;

int main() {
    cin >> R >> C >> M;
    for (int i = 1; i <= M; i++) {
        cin >> a[i].y >> a[i].x >> a[i].s >> a[i].dir >> a[i].size;
        a[i].y--, a[i].x--, a[i].dir--;

        if (a[i].dir <= 1) a[i].s %= (2 * (R - 1));
        else a[i].s %= (2 * (C - 1));

        shark[a[i].y][a[i].x] = i;
    }

    for (int t = 0; t < C; t++) {
        // 1. 상어 잡기
        for (int i = 0; i < R; i++) {
            if (shark[i][t]) {
                ret += a[shark[i][t]].size;
                a[shark[i][t]].death = 1;
                break;
            }
        }

        // 상어 이동
        memset(temp, 0, sizeof(temp));
        for (int i = 1; i <= M; i++) {
            if (a[i].death) continue;
            int y = a[i].y;
            int x = a[i].x;
            int s = a[i].s;
            int d = a[i].dir;
            int z = a[i].size;
            int ny, nx;

            while(true) {
                ny = y + s * dy[d];    
                nx = x + s * dx[d];
                if (ny >= 0 && ny < R && nx >= 0 && nx < C) break;

                if (d <= 1) { // 상하
                    if (ny < 0) {
                        s -= y;
                        y = 0;

                    }
                    else {
                        s -= (R - y - 1);
                        y = R - 1;
                    }
                }
                else { // 좌우
                    if (nx < 0) {
                        s -= x;
                        x = 0;

                    }
                    else {
                        s -= (C - x - 1);
                        x = C - 1;
                    }
                }
                d ^= 1;
            }

            if (temp[ny][nx]) {
                if (a[temp[ny][nx]].size < z) {
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