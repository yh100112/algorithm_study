import java.util.*;
class Solution {
    int[] dy = {-1, 0, 1, 0};
    int[] dx = {0, 1, 0, -1};
    int[][] board = new int[1001][1001];
    boolean[][][] visited = new boolean[1001][1001][2];
    public int solution(int n, int m, int[][] hole) { // m : 세로, n : 가로
        int answer = -1;
        for (int i = 0; i < hole.length; i++)
            board[hole[i][0]][hole[i][1]] = 1;
        
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{1,1,0,0}); // y, x, 신발 사용 여부, 거리
        visited[1][1][0] = true;
        while(!q.isEmpty()) {
            int[] cur = q.poll();
            int y = cur[0];
            int x = cur[1];
            int used = cur[2];
            int dist = cur[3];
            if (y == n && x == m) {
                answer = dist;
                break;
            }
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 1 || ny > n || nx < 1 || nx > m || visited[ny][nx][used] || board[ny][nx] != 0) continue;
                visited[ny][nx][used] = true;
                q.add(new int[]{ny, nx, used, dist + 1});
                if (used == 0)
                    q.add(new int[]{ny + dy[i], nx + dx[i], 1, dist + 1});
            }
        }
        
        return answer;
    }
}