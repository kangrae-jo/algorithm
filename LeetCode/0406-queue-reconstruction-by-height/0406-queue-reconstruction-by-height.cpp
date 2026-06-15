
bool compareTo(const vector<int>& a, const vector<int>& b) {
    if (a[0] == b[0]) return a[1] < b[1];
    return a[0] > b[0];
}

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), compareTo);

        vector<vector<int>> answer;                  
        for(auto person : people) {
            answer.insert(answer.begin() + person[1], person);
        }
        return answer;
    }
};
