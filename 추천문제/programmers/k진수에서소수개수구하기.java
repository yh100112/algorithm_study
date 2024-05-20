import java.util.*;

class Solution {
    String changeNum(int n, int k) {
        String s = "";
        while(n > 0) {
            s = String.valueOf(n % k) + s;
            n /= k;
        }
        return s;
    }
    boolean check(String n) {
        long num = Long.parseLong(n);
        if (num <= 1) return false;
        if (num == 2) return true;
        for (long i = 2; i <= Math.sqrt(num); i++)
            if (num % i == 0) 
                return false;
        return true;
    }
    public int solution(int n, int k) {
        String num = changeNum(n, k);
        String[] arr = num.split("0");
        
        int answer = 0;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i].equals("")) continue;
            if (check(arr[i]) == true)
                answer++;
        }
        return answer;
    }
}