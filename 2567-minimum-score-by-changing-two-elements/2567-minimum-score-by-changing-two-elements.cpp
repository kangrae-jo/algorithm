class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return min(case1(nums), min(case2(nums), case3(nums)));
    }

    int case1(vector<int> nums) {
        nums[0] = nums[2];
        nums[1] = nums[2];
        return nums[nums.size() - 1] - nums[0];
    }

    int case2(vector<int> nums) {
        nums[nums.size() - 1] = nums[nums.size() - 3];
        nums[nums.size() - 2] = nums[nums.size() - 3];
        return nums[nums.size() - 1] - nums[0];
    }

    int case3(vector<int> nums) {
        nums[0] = nums[1];
        nums[nums.size() - 1] = nums[ nums.size() - 2];
        return nums[nums.size() - 1] - nums[0];
    }
};