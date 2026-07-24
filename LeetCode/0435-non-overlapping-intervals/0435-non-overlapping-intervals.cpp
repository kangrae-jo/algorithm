
bool compareTo(const vector<int>& a, const vector<int>& b) {
    if (a[1] == b[1]) return a[1] < b[1];
    return a[1] < b[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 1) return 0;

        sort(intervals.begin(), intervals.end(), compareTo);

        int answer = 0;
        int past = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (past > intervals[i][0]) answer++;
            else past = intervals[i][1];
        }

        return answer;
    }
};
