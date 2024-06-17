import java.util.*;
class Solution {
    int[][] dungeons;
    int[] list;
    int answer;
    public int solution(int k, int[][] dungeons) {
        this.dungeons = dungeons;
        list = new int[dungeons.length];
        for (int i = 0; i < dungeons.length; i++)
            list[i] = i;
        
        makeP(0, k);
        return answer;
    }
    
    void makeP(int idx, int k) {
        if (idx == list.length) {
            int cnt = 0;
            for (int i : list) {
                if (k >= dungeons[i][0]) { // 던전 진입 가능
                    k -= dungeons[i][1];
                    cnt++;
                }
            }
            answer = Math.max(answer, cnt);
            return;
        }
        
        for (int i = idx; i < dungeons.length; i++) {
            swap(idx, i);
            makeP(idx + 1, k);
            swap(idx, i);
        }
    }
    
    void swap(int idx1, int idx2) {
        int temp = list[idx1];
        list[idx1] = list[idx2];
        list[idx2] = temp;
    }
}