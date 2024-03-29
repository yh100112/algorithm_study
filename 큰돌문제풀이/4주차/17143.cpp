#include<bits/stdc++.h>
using namespace std;
#define size aaa
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, 1, -1};
int a[104][104], temp_a[104][104], r, c, s, d, z, m, y, x;
int temp_speed[104][104], temp_size[104][104], temp_dir[104][104];
int speed[104][104], size[104][104], dir[104][104];
int start = -1, ret;

void take() {
    for (int i = 0; i < r; ++i) {
        if(a[i][start]) { // 상어 포획
            ret += size[i][start];
            a[i][start] = 0;
            speed[i][start] = 0;
            dir[i][start] = 0;
            break;
        }
    }
}

void move_shark() {
    fill(&temp_a[0][0], &temp_a[0][0] + 104 * 104, 0);
    fill(&temp_size[0][0], &temp_size[0][0] + 104 * 104, 0);
    fill(&temp_dir[0][0], &temp_dir[0][0] + 104 * 104, 0);
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (a[i][j] == 0) continue;
            int speed_ = speed[i][j]; // speed
            int d = dir[i][j] - 1; // 방향
            int y = i, x = j;
            while(speed_--){
                int ny = y + dy[d];
                int nx = x + dx[d];
                if (ny < 0 || ny >= r || nx < 0 || nx >= c) {
                    if (d == 0) d = 1;
                    if (d == 1) d = 0;
                    if (d == 2) d = 3;
                    if (d == 3) d = 2;
                    ny = y + dy[d];
                    nx = x + dx[d];
                }
                y = ny;
                x = nx;
            }
            if (temp_size[y][x] > size[i][j])
                continue;
            temp_size[y][x] = size[i][j];
            temp_speed[y][x] = speed[i][j];
            temp_dir[y][x] = d + 1;
            temp_a[y][x] = 1;
        }
    }
    for (int i = 0; i < r; ++i) { 
        for (int j = 0; j < c; ++j) {
            cout << temp_size[i][j]<< ' ';
        }
        cout << endl;
    }
    cout << "----------" << endl;

    memcpy(a, temp_a, sizeof(temp_a));
    memcpy(size, temp_size, sizeof(temp_size));
    memcpy(dir, temp_dir, sizeof(temp_dir));
    memcpy(speed, temp_speed, sizeof(temp_speed));
}

int main() {
    cin >> r >> c >> m;
    for (int i = 0; i < m; i++) {
        cin >> y >> x >> s >> d >> z; // 속력, 이동방향, 크기 
        y--, x--;
        a[y][x] = 1; // shark
        speed[y][x] = s;
        dir[y][x] = d;
        size[y][x] = z;
    }

    while(true){
        start++;
        if (start > c) break;
        take();
        move_shark();
        if(start == 2) break;
    }
    cout << ret << "\n";
}