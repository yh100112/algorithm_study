class Solution {
    int[][] arr;
    int[] ret = new int[2];
    public int[] solution(int[][] arr) {
        this.arr = arr;
        
        go(0, 0, arr.length);
        
        return new int[]{ret[0], ret[1]};
    }
    
    void go(int y, int x, int n) {
        boolean diff = false;
        int num = arr[y][x];
        
        for (int i = y; i < y + n; i++)
            for (int j = x; j < x + n; j++)
                if (num != arr[i][j]) diff = true;
        
        if (diff) { // 다른 경우 4등분
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 2; j++)
                    go(y + i * n / 2, x + j * n / 2, n / 2);
        } else {
            ret[num]++;
            return;
        }
    }
}