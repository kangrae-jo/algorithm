
bool compareTo(const vector<int>& a, const vector<int>& b) {
    if (a[0] == b[0]) return a[1] > b[1];
    return a[0] < b[0];
}

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compareTo);

        int answer = 0;
        int start = intervals[0][0];
        int end   = intervals[0][1];
        for (vector<int>& interval : intervals) {
            int start_ = interval[0];
            int end_   = interval[1];
            if (start <= start_ && end_ <= end) answer++;
            else {
                start = start_;
                end = end_;
            }
        }

        return intervals.size() - answer + 1;
    }
};
