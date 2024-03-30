#include<bits/stdc++.h>
#define max_n 100
using namespace std;
struct Shark {
    int y, x, s, dir, z, death;
}a[max_n * max_n];
const int dy[] = {-1, 1, 0, 0}; // 상 하 우 좌
const int dx[] = {0, 0, 1, -1};
int shark[max_n][max_n], R, C, M, ret, temp[max_n][max_n];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C >> M;
    for (int i = 1; i <= M; i++) {
        cin >> a[i].y >> a[i].x >> a[i].s >> a[i].dir >> a[i].z; // 속력, 이동방향, 크기
        a[i].y--; a[i].x--; a[i].dir--;

        // 속도(s) = 이동해야 할 칸 수
        // 왔다 갔다가 전체 크기 * 2이니까 왔다 갔다하는 칸 수를 넘어가는 경우 왔다 갔다해야 할 이동 수를 지우는 것
        if (a[i].dir <= 1) a[i].s %= (2 * (R - 1)); 
        else a[i].s %= (2 * (C - 1));

        shark[a[i].y][a[i].x] = i; // 상어 번호
    }

    for (int t = 0; t < C; t++) { // 열 -> 낚시꾼이 이동하는 것
        // 상어 포획
        for (int y = 0; y < R; y++) {
            if (shark[y][t]) {
                a[shark[y][t]].death = 1;
                ret += a[shark[y][t]].z;
                break;
            }
        }
        memset(temp, 0, sizeof(temp));

        // 상어 이동 ( 상어 마리수만큼 )
        for (int i = 1; i <= M; i++) {
            if (a[i].death) continue;
            int y = a[i].y;
            int x = a[i].x;
            int s = a[i].s; // speed
            int d = a[i].dir; // 방향
            int ny, nx;

            // 최대 2번 도는 반복문 -> 위에서 왔다갔다는 모듈러 연산으로 없앴기 때문
            // 2번 더 도는 경우? -> 중앙에 있어서 왼쪽 오른쪽 벽을 다 치고 방향이 2번 바뀌는 경우
            // 1번 더 도는 경우? -> 벽을 한번 치고 방향이 1번 바뀌는 경우
            // 바로 탈출하는 경우? -> 벽을 닿지 않는 경우
            while(true) {
                ny = y + s * dy[d];
                nx = x + s * dx[d];
                if (ny >= 0 && ny < R && nx >= 0 && nx < C) break; // 범위 안에 있으면

                // 범위를 넘어가는 경우 (벽에 부딪히는 경우)
                if (d <= 1) { // 상 하
                    if (ny < 0) {
                        s -= y;
                        y = 0;
                    }
                    else {
                        s -= R - 1 - y;
                        y = R - 1;
                    }
                }
                else { // 우 좌
                    if (nx < 0) {
                        s -= x; // 이동해야 할 칸 개수에서 처음 위치를 뺸다. ( 처음 위치로 간거라서 그 위치까지의 칸 수는 뺴는 것 )
                        x = 0; // 범위를 벗어나니까 시작위치인 0으로 위치를 바꿈
                    }
                    else {
                        s -= C - 1 - x; // 중간에서 바로 우측끝으로 가는 경우 ( -x가 필요 )
                        x = C - 1;
                    }
                }
                d ^= 1; // 벽에 부딪혀서 방향 전환
            }

            if (temp[ny][nx]) {
                if (a[temp[ny][nx]].z < a[i].z) { // 이미 이 위치에 있는 상어의 크기 < 나중에 이 위치로 온 상어의 크기
                    a[temp[ny][nx]].death = 1;
                    temp[ny][nx] = i;
                }
                else
                    a[i].death = 1;
            }
            else
                temp[ny][nx] = i; // 상어 번호 넣음

            // 상어의 위치와 방향 갱신
            a[i].y = ny;
            a[i].x = nx;
            a[i].dir = d;
        }
        memcpy(shark, temp, sizeof(temp));
    }
    cout << ret << "\n";
}