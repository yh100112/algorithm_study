import java.util.*;
class Solution {
    public int solution(int[] ability, int number) {
        PriorityQueue<Integer> pq = new PriorityQueue<>((n1, n2) -> n1 - n2);
        for (int i : ability)
            pq.add(i);
        
        int answer = 0;
        for (int i = 0; i < number; i++) {
            int sum = pq.poll() + pq.poll();
            pq.add(sum);
            pq.add(sum);
        }
        
        while (!pq.isEmpty())
            answer += pq.poll();
        return answer;
    }
}