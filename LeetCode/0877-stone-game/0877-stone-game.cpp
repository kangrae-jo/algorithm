class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n));

        // 구간에 돌이 하나만 남으면 현재 사람이 그 돌을 얻음
        for (int i = 0; i < n; i++) {
            dp[i][i] = piles[i];
        }

        // 구간 길이 2부터 n까지
        for (int len = 2; len <= n; len++) {
            for (int l = 0; l + len <= n; l++) {
                int r = l + len - 1;

                dp[l][r] = max(
                    piles[l] - dp[l + 1][r],
                    piles[r] - dp[l][r - 1]
                );
            }
        }

        return dp[0][n - 1] >= 0;
    }
};