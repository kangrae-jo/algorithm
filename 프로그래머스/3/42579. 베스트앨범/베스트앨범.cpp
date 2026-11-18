#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    map<string, int> total;
    map<string, map<int, int>> index;
    for (int i = 0; i < genres.size(); i++) {
        total[genres[i]] += plays[i];
        index[genres[i]][i] = plays[i];
    }
    
    vector<pair<string, int>> orderedTotal(total.begin(), total.end());
    sort(orderedTotal.begin(), orderedTotal.end(), [] (const auto& a, const auto& b) {
        return a.second > b.second;
    });
    
    vector<int> answer;
    for (auto& [genre, play] : orderedTotal) {
        vector<pair<int, int>> orderedIndex(index[genre].begin(), index[genre].end());
        sort(orderedIndex.begin(), orderedIndex.end(), [] (const auto& a, const auto& b) {
            return a.second > b.second;
        });
        
        int count = min(2, (int) orderedIndex.size());
        for (int i = 0; i < count; i++) {
            answer.push_back(orderedIndex[i].first);
        }
    }
    
    return answer;
}