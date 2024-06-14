import java.util.*;
class Solution {
    int m, n, ans;
    char[][] a;
    int[] dy = {0, 1, 1}; // 우측, 대각선 아래, 아래
    int[] dx = {1, 1, 0};
    public int solution(int m, int n, String[] board) {
        this.m = m; // 세로
        this.n = n; // 가로
        a = new char[m][n];
        for (int i = 0; i < board.length; i++)
            a[i] = board[i].toCharArray();
        
        while (true) {
            ArrayList<int[]> list = new ArrayList<>(); // 이번 턴에 깨진 블록 위치
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (a[i][j] == 'x') continue;
                    ArrayList<int[]> l = new ArrayList<>();
                    l.add(new int[]{i, j});
                    for (int dir = 0; dir < 3; dir++) {
                        int ny = i + dy[dir];
                        int nx = j + dx[dir];
                        if (ny < 0 || ny >= m || nx < 0 || nx >= n || a[ny][nx] == 'x' || a[i][j] != a[ny][nx]) break;
                        l.add(new int[]{ny, nx});
                    }
                    if (l.size() == 4) {
                        for (int[] p : l)
                            list.add(new int[]{p[0], p[1]});
                    }
                }
            }
            
            // 깨지는 블록 x로 처리
            for (int[] p : list) {
                if (a[p[0]][p[1]] != 'x') { // 중복되서 x처리하는 칸이 아닌 경우
                    a[p[0]][p[1]] = 'x';
                    ans++;
                }
            }
            
            // 열마다 남은 블록 한쪽으로 밀기
            for (int i = 0; i < n; i++) {
                int row = m - 1;
                for (int j = m - 1; j >= 0; j--) {
                    if (a[j][i] == 'x') continue;
                    a[row--][i] = a[j][i];
                }
                for (int j = row; j >= 0; j--)
                    a[j][i] = 'x';
            }
            
            if (list.size() == 0)
                break;
        }
        
        return ans;
    }
}