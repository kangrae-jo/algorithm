
bool compare(const vector<int>& a, const vector<int>& b) {
    if (a[0] == b[0]) return a[1] < b[1];
    return a[0] < b[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);

        vector<vector<int>> answer;
        int prevStart = intervals[0][0];
        int prevEnd   = intervals[0][1];
        for (vector<int> interval : intervals) {
            int start = interval[0];
            int end   = interval[1];

            if (prevEnd >= start) {
                prevEnd = max(prevEnd, end);
            }
            else { 
                answer.push_back({prevStart, prevEnd});
                prevStart = start;
                prevEnd = end;
            }
        }

        answer.push_back({prevStart, prevEnd});
        return answer;
    }
};