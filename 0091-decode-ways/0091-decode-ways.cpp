class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0 || s[0] == '0') {
            return 0;
        }

        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; ++i) {
            int one = s[i - 1] - '0';
            int two = 10 * (s[i - 2] - '0') + (s[i - 1] - '0');

            if (one != 0) dp[i] += dp[i - 1];
            if (10 <= two && two <= 26) dp[i] += dp[i - 2];
        }

        return dp[n];
    }
};
