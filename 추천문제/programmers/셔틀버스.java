import java.util.*;
class Solution {
    public String solution(int n, int t, int m, String[] timetable) {
        String answer = "";
        int[] time_table = new int[timetable.length]; // timetable을 분으로 계산
        for (int i = 0; i < timetable.length; i++) {
            String[] s = timetable[i].split(":");
            time_table[i] = Integer.parseInt(s[0]) * 60 + Integer.parseInt(s[1]);
        }
        Arrays.sort(time_table);
        
        int time = 540; // 09:00 - 셔틀 첫 도착 시간
        int ret = 0, index = 0, person = 0;
        for (int i = 0; i < n; i++) {
            person = 0;
            for (int j = index; j < time_table.length; j++) {
                if (time >= time_table[j]) {
                    person++;
                    index++;
                    if (person == m)
                        break;
                }
            }
            time += t;
        }
        
        if (person < m) {
            ret = time - t;
        } else {
            ret = time_table[index - 1] - 1;
        }
        
        
        String hour = String.valueOf(ret / 60);
        String minute = String.valueOf(ret % 60);
        
        if (hour.length() == 1) hour = "0" + hour;
        if (minute.length() == 1) minute = "0" + minute;
        
        return hour + ":" + minute;
    }
}