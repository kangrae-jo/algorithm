class Solution {
public:
    int maxVowels(string s, int k) {
        int sum = 0;
        for (int i = 0; i < k; i++) {
            if (vowels.contains(s[i])) sum++;
        }
        
        int n = s.length();
        int answer = sum;
        int l = 0, r = k;
        while (r < n) {
            if (vowels.contains(s[r++])) sum++;
            if (vowels.contains(s[l++])) sum--;

            answer = max(answer, sum);
        }

        return answer;
    }
private:
    const string vowels = "aeiou";
};
