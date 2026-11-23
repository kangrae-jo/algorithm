#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    deque<int> dq;
    while (N--) {
        int command;
        cin >> command;
        if (command == 1) {
            int X;
            cin >> X;
            dq.push_front(X);
        } else if (command == 2) {
            int X;
            cin >> X;
            dq.push_back(X);
        } else if (command == 3) {
            if (!dq.empty()) {
                int temp = dq.front();
                dq.pop_front();
                cout << temp << '\n';
            } else {
               cout << "-1\n"; 
            }
        } else if (command == 4) {
            if (!dq.empty()) {
                int temp = dq.back();
                dq.pop_back();
                cout << temp << '\n';
            } else {
               cout << "-1\n"; 
            }
        } else if (command == 5) {
            cout << dq.size() << '\n';
        } else if (command == 6) {
            if (dq.empty()) cout << "1\n";
            else cout << "0\n";
        } else if (command == 7) {
            if (dq.empty()) cout << "-1\n";
            else cout << dq.front() << '\n';
        } else if (command == 8) {
            if (dq.empty()) cout << "-1\n";
            else cout << dq.back() << '\n';
        }
    }
   
    return 0;
}
