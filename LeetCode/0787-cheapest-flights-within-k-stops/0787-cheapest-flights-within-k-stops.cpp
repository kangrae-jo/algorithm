#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    const int INF = 1e9;

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for (vector<int> flight : flights) {
            int out = flight[0];
            int in = flight[1];
            int cost = flight[2];
            graph[out].push_back({in, cost});
        }

        vector<int> distances(n, INF);
        queue<int> q;
        q.push(src);
        distances[src] = 0;

        int level = -1;
        while (!q.empty() && level < k) {
            vector<int> temp = distances;
            int size = q.size();
            while (size-- > 0) {
                int cur = q.front();
                q.pop();

                if (distances[cur] == INF) continue;

                for (auto [next, cost] : graph[cur]) {
                    if (temp[next] <= distances[cur] + cost) continue;
                    temp[next] = distances[cur] + cost;
                    q.push(next);
                }
            }
            distances = temp;
            level++;
        }

        return distances[dst] == INF ? -1 : distances[dst];
    }
};