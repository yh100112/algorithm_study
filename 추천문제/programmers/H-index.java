import java.util.*;
class Solution {
    public int solution(int[] citations) {
        int answer = 0;
        Arrays.sort(citations);
        
        int l = 0, r = 10000;
        int mid = 0;
        while (l <= r) {
            mid = (l + r) / 2; // h편 
            if (check(mid, citations)) {
                answer = mid;
                l = mid + 1;
            } else
                r = mid - 1;
        }
        
        return answer;
    }
    
    boolean check(int h, int[] citations) {
        int[] cnt = new int[2];
        for (int i = 0; i < citations.length; i++) {
            if (h <= citations[i]) // h번 이상 인용
                cnt[0]++;
            else if (h >= citations[i]) // h번 이하 인용
                cnt[1]++;
        }
        return (cnt[0] >= h) && (cnt[1] <= h);
    }
}