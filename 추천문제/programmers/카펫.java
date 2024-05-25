class Solution {
    public int[] solution(int brown, int yellow) {
        int total = brown + yellow;
        
        int row = 0;
        int col = 0;
        for (int i = 1; i <= Math.sqrt(total); i++) {
            if (total % i != 0) continue;
            int n = total / i;
            
            if ((n - 2) * (i - 2) != yellow) continue;
            row = n;
            col = i;
        }
        
        return new int[]{row, col};
    }
}