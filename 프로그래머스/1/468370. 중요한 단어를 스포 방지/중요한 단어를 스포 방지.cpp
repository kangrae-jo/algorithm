#include <string>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

int solution(string message, vector<vector<int>> spoiler_ranges) {
    unordered_map<string, vector<pair<int, int>>> words;
    set<string> words_list;
    
    string temp = "";
    int start = 0;
    for (int i = 0; i < message.size(); i++) {
        char c = message[i];
        if (c == ' ') {
            words_list.insert(temp);
            words[temp].push_back({start, i - 1});
            start = i + 1;
            temp = "";
        }
        else temp += c;
    }
    words_list.insert(temp);
    words[temp].push_back({start, message.size() - 1});

    int answer = 0;
    for (const string& word : words_list) {
        bool in_spoiler = false;
        bool in_normal = false;

        for (const pair<int, int>& pos : words[word]) {
            int word_start = pos.first;
            int word_end = pos.second;

            bool hidden = false;
            for (const vector<int>& spoiler_range : spoiler_ranges) {
                int spoiler_start = spoiler_range[0];
                int spoiler_end = spoiler_range[1];

                if (word_end < spoiler_start || spoiler_end < word_start) continue;
                hidden = true;
                break;
            }

            if (hidden) in_spoiler = true;
            else in_normal = true;
        }

        if (in_spoiler && !in_normal) answer++;
    }

    return answer;
}
