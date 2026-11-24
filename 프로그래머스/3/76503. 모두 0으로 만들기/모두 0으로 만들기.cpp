#include <queue>
#include <vector>
#include <cmath>

using namespace std;

bool canMakeZero(vector<int>& a) {
    long long sum = 0;
    for (int x : a) sum += x;
    return sum == 0 ? true : false;
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    if (!canMakeZero(a)) return -1;
    
    int n = a.size();
    vector<int> indegree(n, 0);
    vector<vector<int>> graph(n);
    
    for (int i = 0; i < edges.size(); i++) {
        int out = edges[i][0];
        int in  = edges[i][1];
        indegree[out]++;
        indegree[in]++;
        graph[out].push_back(in);
        graph[in].push_back(out);
    }
    
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 1) pq.push(i);
    }
        
    vector<long long> weight(a.begin(), a.end());
    long long answer = 0;
    while (!pq.empty()) {
        int cur = pq.top();
        pq.pop();
        
        indegree[cur]--;
                
        for (int next : graph[cur]) {
            if (indegree[next] == 0) continue;
            answer += abs(weight[cur]);
            weight[next] += weight[cur];
            weight[cur] = 0;

            if (--indegree[next] == 1) pq.push(next);
            break;
        }
    }
        
    return answer;
}
