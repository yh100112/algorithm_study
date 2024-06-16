import java.util.*;
class Solution {
    ArrayList<ArrayList<Integer>> a = new ArrayList<>(); // 송전탑 상태를 저장할 인접 리스트
    int answer = Integer.MAX_VALUE;
    public int solution(int n, int[][] wires) {
        for (int i = 0; i <= n; i++)
            a.add(new ArrayList<>());

        // 인접 리스트 초기 상태 세팅
        for (int i = 0; i < wires.length; i++) {
            int s = wires[i][0];
            int e = wires[i][1];
            a.get(s).add(e);
            a.get(e).add(s);
        }

        // 간선(n - 1개)들 중 한개 없애고 탐색  - max, min 구하기
        for (int i = 0; i < wires.length; i++) {
            int[] visited = new int[n + 1];
            
            int v1 = wires[i][0];
            int v2 = wires[i][1];
            a.get(v1).remove(Integer.valueOf(v2));
            a.get(v2).remove(Integer.valueOf(v1));
			
            int cnt = dfs(1, visited);
            int diff = Math.abs(cnt - (n - cnt));
            answer = Math.min(answer, diff);

            a.get(v1).add(v2);
            a.get(v2).add(v1);
        }

        return answer;
    }

    int dfs(int num, int[] visited) {
        visited[num] = 1;
        int ret = 1;
        for (int next : a.get(num)) {
            if (visited[next] == 1) continue;
            ret += dfs(next, visited);
        }
        return ret;
    }
}