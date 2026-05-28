class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1e9);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            int endIndex = min(n - 1, i + nums[i]);
            for (int next = i + 1; next <= endIndex; next++) {
                dp[next] = min(dp[next], dp[i] + 1);
            }
        }

        return dp[n - 1];
    }
};
