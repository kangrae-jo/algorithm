#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    map<string, int> answer;
    while (N--) {
        string word;
        cin >> word;
        
        if (word.length() < M) continue;
        
        answer[word]++;
    }
    
    vector<pair<string, int>> result(answer.begin(), answer.end());

    sort(result.begin(), result.end(), [](const auto& a, const auto& b) {
        if (a.second != b.second) {
            return a.second > b.second;
        }
    
        if (a.first.length() != b.first.length()) {
            return a.first.length() > b.first.length();
        }
    
        return a.first < b.first;
    });
    
    for (auto& [word, cnt] : result) {
        cout << word << '\n';
    }
    
    return 0;
}
