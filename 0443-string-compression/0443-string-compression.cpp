class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int index = 0;

        vector<char> result;
        while (index < n) {
            char now = chars[index];
            int pointer = 0;

            while (index + pointer < n && chars[index + pointer] == now) {
                pointer++;
            }
            result.push_back(now);

            if (pointer > 1) {
                string count = to_string(pointer);
                for (char c : count) result.push_back(c);
            }
            index += pointer;
        }

        chars = result;
        return chars.size();
    }
};
