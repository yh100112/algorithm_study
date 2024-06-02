class Solution {
    public int solution(String skill, String[] skill_trees) {
        int answer = 0;
        String[] skillList = skill.split(""); // "c", "b", "d"
        for (String skillTree : skill_trees) {
            boolean flag = true;
            // ("c", "b"), ("b", "d") 순서 체크
            for (int i = 1; i < skillList.length; i++) {
                // 유저가 만든 스킬트리에서 선행, 후행 스킬들이 순서대로 있는지 체크
                int end = skillTree.indexOf(skillList[i]); // 후행스킬
                int start = skillTree.indexOf(skillList[i - 1]);  // 선행스킬
                
                if (start == -1) {
                    if (end != -1)
                        flag = false;
                }
                else
                    if (end != -1 && end < start) // 선행스킬이 후행스킬보다 더 나중에 나올 때
                        flag = false;
                if (!flag) break;
            }
            if(flag) answer++;
        }
        return answer;
    }
}