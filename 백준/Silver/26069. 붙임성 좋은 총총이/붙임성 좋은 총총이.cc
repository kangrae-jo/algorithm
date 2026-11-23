#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    unordered_set<string> us;
    us.insert("ChongChong");
    
    for (int i = 0; i < N; i++) {
        string in, out;
        cin >> in >> out;
        
        if (us.find(in) != us.end()) {
            us.insert(out);
        } else if (us.find(out) != us.end()) {
            us.insert(in);
        }   
    }
    
    cout << us.size() << '\n';
    
    return 0;
}
