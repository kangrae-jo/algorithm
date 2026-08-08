class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int answer = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[answer] < nums[i]) {
                answer = i;
            }
        }

        return answer;
    }
};
