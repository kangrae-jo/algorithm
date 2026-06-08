
bool compare(string a, string b) {
    return a + b > b + a;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> numbers(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            numbers[i] = to_string(nums[i]);
        }

        sort(numbers.begin(), numbers.end(), compare);

        string answer = "";
        for (string number : numbers) answer += number;

        for (char c : answer) {
            if (c != '0') return answer;
        }

        return "0";
    }
};
