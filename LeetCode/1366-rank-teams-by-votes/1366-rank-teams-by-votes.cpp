
class Solution {
    const int ALPHA_SIZE = 26;
public:
    string rankTeams(vector<string>& votes) {
        vector<vector<int>> count(ALPHA_SIZE, vector<int>(ALPHA_SIZE + 1));
        for (char& c : votes[0]) {
            count[c - 'A'][ALPHA_SIZE] = c;
        }

        for (string& vote: votes) {
            for (int i = 0; i < vote.length(); i++) {
                count[vote[i] - 'A'][i]--;
            }
        }
        
        sort(count.begin(), count.end());
        
        string res;
        for (int i = 0; i < votes[0].length(); i++) {
            res += count[i][ALPHA_SIZE];
        }

        return res;
    }
};
//1350~