class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int len = n + 1;

        int sum = 0;
        int left = 0;
        for (int right = 0; right < n; right++) {
            sum += nums[right];
            while (sum >= target) {
                len = min(len, right - left + 1);
                sum -= nums[left++];
            }
        }

        return len == n + 1 ? 0 : len;
    }
};
