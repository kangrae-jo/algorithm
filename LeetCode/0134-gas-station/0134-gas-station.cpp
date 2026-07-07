class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalGas = 0, totalCost = 0;
        int curGas = 0, start = 0;

        for (int i = start; i < n; i++) {
            totalGas += gas[i];
            totalCost += cost[i];

            curGas += gas[i] - cost[i];
            if (curGas < 0) {
                start = i + 1;
                curGas = 0;
            }
        }
        return (totalGas < totalCost) ? -1 : start;     
    }
};
