import java.util.*;

class Solution {
    public int solution(int[][] jobs) {
        int answer = 0;
        int time = 0; // 현재 시점의 시간
        int idx = 0; // jobs 순서
        
        Arrays.sort(jobs, (o1, o2) -> o1[0] - o2[0]); // 작업 요청시점을 기준으로 오름차순
       	Queue<int[]> pq = new PriorityQueue<>((o1, o2) -> o1[1] - o2[1]); // 소요시간을 기준으로 오름차순
        
        while (!pq.isEmpty() || idx < jobs.length) {
            // 현재 시점보다 작업 요청시점이 이전인 작업은 pq에 전부 넣음
            while (idx < jobs.length && jobs[idx][0] <= time)
                pq.add(jobs[idx++]);
            
            if (!pq.isEmpty()) {
                int[] job = pq.poll(); // 현재 시점보다 작업 요청시점이 이전인 작업들 중 가장 소요시간이 짦은 작업 먼저 처리
                time += job[1];
                answer += time - job[0];
            }
            else
                time = jobs[idx][0]; // 작업 요청시점이 가장 빠른 작업부터 다시 시작
        }
        
        return answer / jobs.length;
    }
}
