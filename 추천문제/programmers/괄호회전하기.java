import java.util.*;
class Solution {
    public int solution(String s) {
        int answer = 0;
        char[] arr = s.toCharArray();
        int len = arr.length;

        // 한 칸씩 왼쪽으로 이동
        for (int k = 0; k < len; k++) {
            Stack<Character> st = new Stack<>();
            for (int i = k; i < k + len; i++) {
                Character c = arr[i % len];
                if (!st.isEmpty()) {
                    if (st.peek() == '[' && c == ']')
                        st.pop();
                    else if (st.peek() == '(' && c == ')')
                        st.pop();
                    else if (st.peek() == '{' && c == '}')
                        st.pop();
                    else
                        st.push(c);
                } else {
                    st.push(c);
                }
            }
            if (st.isEmpty())
                answer++;
        }

        return answer;
    }
}
// s를 왼쪽으로 x만큼 이동