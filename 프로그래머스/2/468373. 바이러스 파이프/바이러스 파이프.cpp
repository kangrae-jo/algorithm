#include <queue>
#include <vector>
#include <iostream>

using namespace std;

int bfs(vector<vector<pair<int, int>>>& graph, int infection, vector<int> types) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    q.push(infection);
    visited[infection] = true;
    
    int count = 1;
    for (int type : types) {
        // cout << "type : " << type << endl;
        queue<int> temp;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            
            // cout << "cur : " << cur << endl;
            
            for (auto [next, next_type] : graph[cur]) {
                if (visited[next]) continue;
                if (next_type == type) {
                    q.push(next);
                    count++;
                    visited[next] = true;
                } else temp.push(cur);
            }
        }
        
        while (!temp.empty()) {
            q.push(temp.front());
            temp.pop();
        }
    }
    
    return count;
}

int backtracking(vector<vector<pair<int, int>>>& graph, int infection, vector<int> types, int k) {
    if (k == types.size()) {
        // cout << "\nnew bfs; ---------- \n";
        return bfs(graph, infection, types);
    }
    
    int answer = 0;
    for (int type = 1; type <= 3; type++) {
        types.push_back(type);
        answer = max(answer, backtracking(graph, infection, types, k));
        types.pop_back();
    }
    
    return answer;
}

int solution(int n, int infection, vector<vector<int>> edges, int k) {
    vector<vector<pair<int, int>>> graph(n + 1);
    for (vector<int> edge : edges) {
        int out = edge[0];
        int in = edge[1];
        int type = edge[2];
        
        graph[in].push_back({out, type});       
        graph[out].push_back({in, type});       
    }
    
    
    return backtracking(graph, infection, {}, k);
}
