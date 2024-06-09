class Solution {
    public String solution(int n, int t, int m, int p) {
        int num = 0, cnt = 0; // num : 숫자, cnt : 순서
        String answer = "";
        while(t > 0) {
            String cNum = change(n, num); // 진법 변환된 숫자를 문자열로 바꾼 상태 ( 범위를 넘어가는 긴 숫자가 나올 수 있기 때문)
            
            for (int i = 0; i < cNum.length(); i++) { // 문자열 길이만큼 순서를 돌림 -> 10이면 1, 0을 호출하는 걸 처리
                if (cnt % m == p - 1) { // 튜브 순서
                    answer += cNum.charAt(i);
                    t--;
                    if (t == 0) break;
                }
                cnt++;
            }
            num++;
        }
        
        return answer;
    }
    
    String change(int n, int num) {
        if (num == 0) return "0";
        String str = "";
        while(num > 0) {
            String s = "";
            int temp = num % n;
            switch(temp) {
                case 10: s = "A"; break;
                case 11: s = "B"; break;
                case 12: s = "C"; break;
                case 13: s = "D"; break;
                case 14: s = "E"; break;
                case 15: s = "F"; break;
                default: s = String.valueOf(num % n); break;
            }
            str = s + str;
            num /= n;
        }
        
        return str;
    }
}