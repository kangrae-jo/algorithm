class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> answer;
        backtracking(0, answer, "", digits);

        return answer;
    }

private:
    map<char, string> phoneNumbers = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    void backtracking (int k, vector<string>& answer, string temp, string& digits) {
        if (temp.size() == digits.size()) {
            answer.push_back(temp);
            return;
        }

        char number = digits[k];
        for (char c : phoneNumbers[number]) {
            temp.push_back(c);
            backtracking(k + 1, answer, temp, digits);
            temp.pop_back();
        }
    }

};
