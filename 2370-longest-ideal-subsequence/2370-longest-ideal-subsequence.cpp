class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> dp(26, 0);
        int answer = 0;
        for (char ch : s) {
            int c = ch - 'a';
            int best = 0;
            for (int v = max(0, c - k); v <= min(25, c + k); v++) {
                best = max(best, dp[v]);
            }

            dp[c] = best + 1;
            answer = max(answer, dp[c]);
        }

        return answer;
    }
};