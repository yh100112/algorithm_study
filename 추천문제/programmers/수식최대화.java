import java.util.*;
class Solution {
    public long solution(String expression) {
        long answer = Long.MIN_VALUE;
        String[][] op = {
            {"*", "-", "+"}, {"*", "+", "-"}, {"-", "+", "*"}, {"-", "*", "+"}, {"+", "-", "*"},
            {"+", "*", "-"}
        };
        
        ArrayList<String> list = new ArrayList<>();
        int start = 0;
        for (int i = 0; i < expression.length(); i++) {
            char c = expression.charAt(i);
            if (c == '-' || c == '+' || c == '*') {
                list.add(expression.substring(start, i)); // 연산자 앞 숫자 추가
                list.add(expression.charAt(i) + ""); // 연산자 추가
                start = i + 1;
            }
        }
        list.add(expression.substring(start)); // 마지막 숫자 추가
        
        // 연산자 우선순위 6개 조합
        for (int i = 0; i < op.length; i++) {
            ArrayList<String> sub_list = new ArrayList<>(list);
            // 연산자 우선순위 순서대로 계산
            for (int k = 0; k < 3; k++) {
                for (int j = 0; j < sub_list.size(); j++) {
                    // 현재 순위의 연산자를 만나면
                    if (op[i][k].equals(sub_list.get(j))) {
                        sub_list.set(j - 1, calc(sub_list.get(j - 1), sub_list.get(j), sub_list.get(j + 1)));
                        sub_list.remove(j);
                        sub_list.remove(j);
                        j--;
                    }
                }
            }
            answer = Math.max(answer, Math.abs(Long.parseLong(sub_list.get(0))));
        }
        
        return answer;
    }
    
    String calc(String num1, String op, String num2) {
        long n1 = Long.parseLong(num1);
        long n2 = Long.parseLong(num2);
        
        if (op.equals("+")) return String.valueOf(n1 + n2);
        if (op.equals("-")) return String.valueOf(n1 - n2);
        return String.valueOf(n1 * n2);
    } 
}