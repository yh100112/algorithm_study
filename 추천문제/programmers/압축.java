import java.util.*;
class Solution {
    public ArrayList<Integer> solution(String msg) {
        ArrayList<Integer> ret = new ArrayList<>();
        HashMap<String, Integer> hm = new HashMap<>();
        int index = 0; // 색인 번호
        for (int i = 'A'; i <= 'Z'; i++)
            hm.put(String.valueOf((char)i), ++index);
        
        while (msg.length() > 0) {
            String init = String.valueOf(msg.charAt(0));
            String str = init;
            String max_str = str;
            int max_length = 1;
            int max_str_idx = 0;
            for (int j = 1; j < msg.length(); j++) {
                str += msg.charAt(j); // 다음 글자 추가
                if (hm.containsKey(str) && max_length < str.length()) {
                    max_str = str;
                    max_length = str.length();
                    max_str_idx = j;
                }
            }
            ret.add(hm.get(max_str));
            if (max_str_idx < msg.length() - 1)
                hm.put(max_str + msg.charAt(max_str_idx + 1), ++index);
            msg = msg.substring(max_str.length());
        }
        
        int[] answer = new int[ret.size()]; 
        for (int i = 0; i < ret.size(); i++)
            answer[i] = ret.get(i);
        
        return ret;
    }
}