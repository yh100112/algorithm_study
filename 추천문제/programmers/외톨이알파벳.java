class Solution {
    public String solution(String input_string) {
        int[] arr = new int[26];
        int pre = input_string.charAt(0);
        arr[pre - 'a']++;

        for(int i = 1; i < input_string.length(); i++){
            if(input_string.charAt(i) != pre){
                pre = input_string.charAt(i);
                arr[pre - 'a']++;
            }
        }
        String answer = "";
        for(int i = 0; i<arr.length; i++){
            if(arr[i] >= 2){
                answer += (char)(i + 'a');
            }
        }
        return answer=="" ? "N" : answer;
    }
}