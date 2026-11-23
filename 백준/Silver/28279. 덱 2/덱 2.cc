#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;
    
    deque<int> dq;    
    while (N--) {
        int command, X, temp;
        cin >> command;
        
        switch(command){
            case 1:
                cin >> X;
                dq.push_front(X);
                break;
            case 2: 
                cin >> X;
                dq.push_back(X);
                break;
            case 3: 
                if (!dq.empty()) {
                    temp = dq.front();
                    dq.pop_front();
                    cout << temp << '\n';
                } else {
                   cout << "-1\n"; 
                }
                break;
           case 4:
                if (!dq.empty()) {
                    temp = dq.back();
                    dq.pop_back();
                    cout << temp << '\n';
                } else {
                   cout << "-1\n"; 
                }
                break;
            case 5: 
                cout << dq.size() << '\n';
                break;
            case 6: 
                if (dq.empty()) cout << "1\n";
                else cout << "0\n";
                break;
            case 7: 
                 if (dq.empty()) cout << "-1\n";
                else cout << dq.front() << '\n';
                break;
            case 8: 
                if (dq.empty()) cout << "-1\n";
                else cout << dq.back() << '\n';
                break;
        }
    }
        
    return 0;
}
