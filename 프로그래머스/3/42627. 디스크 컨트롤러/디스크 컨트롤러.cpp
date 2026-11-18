#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(), jobs.end());
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; 
    int answer = 0;
    int now = 0;
    int i = 0;
    
    while (i < jobs.size() || !pq.empty()) {
        while(i < jobs.size() && now >= jobs[i][0]) {
            pq.push({jobs[i][1], jobs[i][0]});
            i++;
        }
        
        if (!pq.empty()) {
            auto [time, start] = pq.top();
            pq.pop();
            
            now += time;
            answer += now - start;
        }
        else now = jobs[i][0];
    }
    
    return answer / jobs.size();
}