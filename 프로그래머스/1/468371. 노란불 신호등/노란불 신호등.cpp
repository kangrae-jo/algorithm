#include <vector>
#include <numeric>

using namespace std;

int solution(vector<vector<int>> signals) {
    int n = signals.size();
    int max = 1;
    for (int i = 0; i < n; i++) {
        max = lcm(max, signals[i][0] + signals[i][1] + signals[i][2]);
    }
    
    vector<vector<bool>> time(max, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        int period = signals[i][0] + signals[i][1] + signals[i][2];
        for (int j = 0; j < max; j += period) {
            for (int k = 0; k < signals[i][1]; k++) {
                time[j + signals[i][0] + k][i] = true;
            }
        }
    }
    
    for (int i = 0; i < max; i++) {
        bool flag = true;
        for (int j = 0; j < n; j++) {
            if (!time[i][j]) {
                flag = false;
                break;
            }
        }
        if (flag) return i + 1;
    }
    return -1;
}
