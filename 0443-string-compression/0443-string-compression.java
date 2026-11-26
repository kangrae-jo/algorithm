class Solution {
    public int compress(char[] chars) {
        int n = chars.length;
        
        int answer = 0;
        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && chars[j] == chars[i]) j++;

            chars[answer++] = chars[i];

            int count = j - i;
            if (count > 1) {
                String num = String.valueOf(count);
                for (int k = 0; k < num.length(); k++) {
                    chars[answer++] = num.charAt(k);
                }
            }
            i = j;
        }

        return answer;
    }
}
