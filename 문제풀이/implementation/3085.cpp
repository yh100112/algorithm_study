#include<bits/stdc++.h>
using namespace std;
int n;
char ori[54][54];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> ori[i][j];

    int mx = -1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int curX = i;
            int curY = j;
            for(int ret = 0; ret < 4; ret++){
                int nx = curX + dx[ret];
                int ny = curY + dy[ret];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (ori[curX][curY] != ori[nx][ny]) {
                    swap(ori[curX][curY], ori[nx][ny]);
                    for(int row = 0; row < n; row++){
                        int first = ori[row][0];
                        int cnt = 0;
                        for(int col = 0; col < n; col++){ // 행 체크
                            if(first == ori[row][col]){
                                cnt++;
                            }
                            else{
                                cnt = 1;
                                first = ori[row][col];
                            }
                        }
                        int first_col = ori[0][row];
                        int index = row;
                        int cnt2 = 0;
                        for(int col = 0; col < n; col++){ // 열 체크
                            index += n;
                            if(first_col == ori[index][row]){
                                cnt2++;
                            }
                            else{
                                cnt2 = 1;
                                first_col = ori[index][row];
                            }
                        }
                        int m = max(cnt,cnt2);
                        mx = max(m,mx);
                    }
                    swap(ori[curX][curY], ori[nx][ny]);
                }
            }
        }
    }
    cout << mx << "\n";
}