import java.util.*;
class Solution {
    String[] pattern = {"A", "E", "I", "O", "U"};
    ArrayList<String> arr = new ArrayList<>();
    int cnt = 0;
    public int solution(String word) {
        go(0, "");
        int answer = 0;
        for (String s : arr) {
            if (s.equals(word))
                break;
            answer++;
        }
        return answer;
    }
    
    void go(int idx, String s) {
        arr.add(s);
        if (idx == 5)
            return;
        for (int i = 0; i < 5; i++)
            go(idx + 1, s + pattern[i]);
    }
}