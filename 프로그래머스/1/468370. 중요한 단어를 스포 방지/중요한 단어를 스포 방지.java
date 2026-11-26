import java.util.*;

class Solution {
    public int solution(String message, int[][] spoilerRanges) {
        int n = message.length();
        
        boolean[] hidden = new boolean[n];
        for (int[] spoilerRange : spoilerRanges) {
            int start = spoilerRange[0];
            int end = spoilerRange[1];
            for (int i = start; i <= end; i++) {
                hidden[i] = true;
            }
        }
        
        Set<String> spoilers = new HashSet<>(); 
        Set<String> normals = new HashSet<>(); 
        
        String word = "";
        boolean flag = false;
        for (int i = 0; i < n; i++) {
            char c = message.charAt(i);

            if (c != ' ') {
                word += c;
                if (hidden[i]) flag = true;
            }

            if (c == ' ' || i == n - 1) {
                if (word.length() > 0) {
                    if (flag) spoilers.add(word);
                    else normals.add(word);
                }

                word = "";
                flag = false;
            }
        }
         
        int answer = 0;
        for (String spoiler : spoilers) {
            if (!normals.contains(spoiler)) {
                answer++;
            }
        }
            
        return answer;
    }
}