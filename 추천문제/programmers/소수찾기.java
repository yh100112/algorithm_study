import java.util.*;
class Solution {
    int answer;
    String numbers;
    boolean[] isused;
    HashMap<String, Boolean> m = new HashMap<>();
    public int solution(String numbers) {
        this.numbers = numbers;
        isused = new boolean[numbers.length()];
        go(0, "");
        
        return answer;
    }
    
    void go(int idx, String s) {
        if (!s.isEmpty()) {
            while (!s.isEmpty() && s.charAt(0) == '0')
                s = new StringBuilder(s).deleteCharAt(0).toString();
            if (!s.isEmpty() && m.containsKey(s) == false) {
            	m.put(s, true);
                if (check(s))
                    answer++;
            }
        }
        if (idx == numbers.length())
            return;
        
        for (int i = 0; i < numbers.length(); i++) {
            if (isused[i]) continue;
            isused[i] = true;
            go(idx + 1, s + numbers.charAt(i));
            isused[i] = false;
        }
    }
    
    boolean check(String s) {
        int num = Integer.parseInt(s);
        if (num <= 1) return false;
        if (num == 2) return true;
        for (int i = 2; i <= Math.sqrt(num); i++)
            if (num % i == 0)
                return false;
        return true;
    }
}