#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(), jobs.end());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    
    int wait = 0, index = 0, now = 0;
    int n = jobs.size();
    
    while (index < n || !pq.empty()) {
        while (index < n && jobs[index][0] <= now) {
            pq.push({jobs[index][1], jobs[index][0]});
            index++;
        }
        
        if (!pq.empty()) {
            auto [time, start] = pq.top();
            pq.pop();
            
            now += time;
            wait += now - start;
        }
        else now = jobs[index][0];
    }
    
    return wait / n;
}