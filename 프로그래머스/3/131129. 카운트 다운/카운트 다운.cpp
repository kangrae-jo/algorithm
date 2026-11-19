#include <vector>
#include <algorithm>

using namespace std;

void first(vector<pair<int, int>>& dp, int cur, int next) {
    if (next >= dp.size()) return;
    if ((dp[cur].first + 1) < (dp[next].first) 
        || ((dp[cur].first + 1) == (dp[next].first) && (dp[cur].second) > (dp[next].second))) {
         dp[next] = {dp[cur].first + 1, dp[cur].second};
    } 
}

void second(vector<pair<int, int>>& dp, int cur, int next) {
    if (next >= dp.size()) return;
    if ((dp[cur].first + 1) < (dp[next].first) 
        || ((dp[cur].first + 1) == (dp[next].first) && (dp[cur].second + 1) > (dp[next].second))) {
         dp[next] = {dp[cur].first + 1, dp[cur].second + 1};
    } 
}

vector<int> solution(int target) {
    vector<pair<int, int>> dp(target + 1, {1e9, 1e9});
    dp[0] = {0, 0};
    
    for (int cur = 0; cur <= target; cur++) {  
        second(dp, cur, cur + 50);
        for (int score = 1; score <= 20; score++) {
            second(dp, cur, cur + score);
            first(dp, cur, cur + score * 2);
            first(dp, cur, cur + score * 3);
        }
    }
    
    return {dp[target].first, dp[target].second};
}
