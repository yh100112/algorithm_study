class Solution {
    public String[] solution(int[][] queries) {
        String[] result = new String[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int n = queries[i][0];
            int p = queries[i][1];
            result[i] = n == 1 ? "Rr" : recursive(n, p);
        }
        return result;
    }
    
    String recursive(int n, int p) {
        int total = (int)Math.pow(4, n - 1); // 현재 세대의 완두콩 개수
        if (p <= total / 4) return "RR";
        if (p > total / 4 * 3) return "rr";
        if (n == 2) return "Rr";
        if (p <= total / 4 * 2) return recursive(n - 1, p - total / 4);
        return recursive(n - 1, p - total / 2);
    }
}