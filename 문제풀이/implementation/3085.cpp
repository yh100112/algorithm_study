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
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int ret = 0; ret < 4; ret++) {
                int nx = i + dx[ret];
                int ny = j + dy[ret];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                swap(ori[i][j], ori[nx][ny]);
                // 교환 후 행합 구함
                int max_row = -1; // 행 중 제일 큰 연속된 사탕갯수
                for(int row = 0; row < n; row++){
                    int first = ori[row][0];
                    int cnt = 0;
                    int m_cnt = -1;
                    // 행에서 연속된 제일 큰 값 구함
                    for(int col = 0; col < n; col++){
                        if(first == ori[row][col]) {
                            cnt++;
                            m_cnt = max(m_cnt, cnt);
                        }
                        else {
                            cnt = 1;
                            first = ori[row][col];
                        }
                    }
                    max_row = max(m_cnt, max_row);
                }
                int max_col = -1; // 열 중 제일 큰 연속된 사탕갯수
                for(int col = 0; col < n; col++){
                    int first = ori[0][col];
                    int cnt2 = 0;
                    int m_cnt = -1;
                    // 열에서 연속된 제일 큰 값 구함
                    for(int row = 0; row < n; row++){
                        if(first == ori[row][col]){
                            cnt2++;
                            m_cnt = max(m_cnt, cnt2);
                        }
                        else{
                            cnt2 = 1;
                            first = ori[row][col];
                        }
                    }
                    max_col = max(m_cnt, max_col);
                }
                swap(ori[i][j], ori[nx][ny]);
                int m = max(max_row, max_col);
                mx = max(m,mx);
            }
        }
    }
    cout << mx << "\n";
}