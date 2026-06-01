
class Solution {
    const int RED = 0;
    const int WHITE = 1;
    const int BLUE = 2;

public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        vector<int> counts(3, 0);
        for (int i = 0; i < n; i++) {
            counts[nums[i]]++;
        }

        int i = 0;
        for (int c = 0; c < 3; c++) {
            for (int j = 0; j < counts[c]; j++) {
                nums[i++] = c;
            }
        }
    }
};
