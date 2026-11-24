#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<string> strs, string t) {
    set<string> s(strs.begin(), strs.end());
    
    int n = t.size();
    vector<int> dp(n + 1, 1e9);    
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= 5 && i + j <= n; j++) {
            if (s.find(t.substr(i, j)) != s.end()) {
                if (i == 0) dp[i + j] = 1;
                else dp[i + j] = min(dp[i + j], dp[i] + 1);
            }
        }
    }
    
    return dp[n] == 1e9 ? -1 : dp[n];
}