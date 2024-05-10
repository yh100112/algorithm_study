class Solution {
    static final int[] dy = {1, 0, -1}; // 하, 우, 좌상
    static final int[] dx = {0, 1, -1};
    public int[] solution(int n) {
        int[][] arr = new int[1004][1004];
        int[][] visited = new int[1004][1004];
        int len = 0, num = 1, dir = 0, x = 0, y = 0;
        arr[0][0] = num++;
        visited[0][0] = 1;
        for (int i = n; i > 0; i--) len += i;
        while(num <= len) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if (ny >= n || nx >= n || visited[ny][nx] == 1) {
                dir = (dir + 1) % 3;
                continue;
            }
            visited[ny][nx] = 1;
            arr[ny][nx] = num++;
            y = ny;
            x = nx;
        }
        
        int[] ans = new int[len];
        int idx = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == 0) break;
                ans[idx++] = arr[i][j];
            }
        
        return ans;
    }
}