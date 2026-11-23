#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    int answer = 0;
    unordered_set<string> us;
    while (N--) {
        string input;
        cin >> input;
        
        if (input == "ENTER") {
            us.clear();
        } else if (us.find(input) == us.end()) {
                answer++;
                us.insert(input);
            }
    }
    cout << answer << '\n';
    
    return 0;
}
