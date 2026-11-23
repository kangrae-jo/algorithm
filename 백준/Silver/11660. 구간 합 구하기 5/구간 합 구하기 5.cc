#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> prefix(N + 1, vector<int>(N + 1, 0));
    for(int y = 0; y < N; y++) {
        int sum = 0;
        for (int x = 0; x < N; x++) {
            int temp;
            cin >> temp;
            
            sum += temp;
            prefix[y + 1][x + 1] = sum + prefix[y][x + 1];
        }
    }
    
    while (M--) {
        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        
        int answer =  prefix[y2][x2]
            - prefix[y2][x1 - 1]
            - prefix[y1 - 1][x2]
            + prefix[y1 - 1][x1 - 1];
            
        cout << answer << '\n';
    }
    
    return 0;
}
