class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int answer = 0;
        for (int longest = nums.size() - 1; longest >= 2; longest--) {
            for (int p = 0; p <= longest - 2; p++) {
                for (int q = p + 1; q <= longest - 1; q++) {
                    if (nums[longest] < nums[p] + nums[q]) answer++;
                }
            }
        }

        return answer;
    }
};