import java.util.*;
class Solution {
    public int[] solution(int[][] edges) {
        Map<Integer, int[]> node = new HashMap<>();
        int[] answer = {0, 0, 0, 0};
        
        for (int[] edge : edges) {
            int a = edge[0]; // 간선이 나가는 노드
            int b = edge[1]; // a에서 간선이 나와서 도착하는 노드 b
            if (!node.containsKey(a))
                node.put(a, new int[]{0, 0});
            if (!node.containsKey(b))
                node.put(b, new int[]{0, 0});
            node.get(a)[0] += 1; // 나가는 간선
            node.get(b)[1] += 1; // 들어오는 간선
        }
        
        int[] cnts;
        for (int key : node.keySet()) {
            cnts = node.get(key);
            
            // 나가는 간선이 2개 이상이고 들어오는 간선이 없는 경우 -> 정점
            if (cnts[0] >= 2 && cnts[1] == 0)
                answer[0] = key;
            // 나가는 간선이 없고, 들어오는 간선만 있는 경우 -> 막대 그래프
            else if (cnts[0] == 0 && cnts[1] > 0)
                answer[2]++;
            // 나가는 간선이 2개 이상이고 들어오는 간선도 2개 이상인 경우 -> 8자 그래프
            else if (cnts[0] == 2 && cnts[1] == 2)
                answer[3]++;
        }
        
        answer[1] = node.get(answer[0])[0] - answer[2] - answer[3];
        return answer;
    }
}