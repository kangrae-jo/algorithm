class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int answer = 0;
        int l = 0, r = people.size() - 1;
        while (l <= r) {
            int sum = people[l] + people[r];
            if (sum <= limit) l++;
            r--;
            answer++;
        }

        return answer;
    }
};
