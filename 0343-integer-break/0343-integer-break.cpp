class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) return n - 1;

        vector<int> dp(n + 1, 1);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;

        for (int i = 3; i <= n; i++) {
            int one = dp[i - 1];
            int two = dp[i - 2] * 2;
            int three = dp[i - 3] * 3;
            dp[i] = max(one, max(two, three));
        }

        return dp[n];
    }
};
