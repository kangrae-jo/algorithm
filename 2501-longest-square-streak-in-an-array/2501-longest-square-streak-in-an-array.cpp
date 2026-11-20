class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        unordered_map<int, int> dp;
        int answer = 0;

        for (int num : nums) {
            int r = (int) sqrt(num);
            if (r * r == num && dp.count(r)) dp[num] = dp[r] + 1;
            else dp[num] = 1;
            answer = max(answer, dp[num]);
        }
        return answer >= 2 ? answer : -1;
    }
};