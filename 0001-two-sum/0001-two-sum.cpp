class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> um;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if (um.count(complement)) {
                return {um[complement], i};
            }
            um[nums[i]] = i;
        }

        return {};
    }
};
