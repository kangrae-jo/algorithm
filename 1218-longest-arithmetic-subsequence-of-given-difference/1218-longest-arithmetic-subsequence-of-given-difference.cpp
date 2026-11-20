class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> dp;
        int answer = 0;
        for (int num : arr) {
            dp[num] = dp[num - difference] + 1;
            answer = max({answer, dp[num]});
        }


        return answer;
    }
};