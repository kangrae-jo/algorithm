class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (gas.size() == 1) {
            if (gas[0] >= cost[0]) return 0;
            else return -1;
        }

        for (int start = 0; start < gas.size(); start++) {
            if (canTravelAt(start, gas, cost)) return start;
        }
        return -1;
    }

private:
    bool canTravelAt(int start, vector<int>& gas, vector<int>& cost) {
        if (gas[start] <= cost[start]) return false;

        int n = gas.size();
        int amount = gas[start];
        int prev = start;

        for (int offset = 1; offset <= n; offset++) {
            int point = (start + offset) % n;
            amount -= cost[prev];
            if (amount < 0) return false;
            amount += gas[point];
            prev = point;
        }
        return true;
    }
};