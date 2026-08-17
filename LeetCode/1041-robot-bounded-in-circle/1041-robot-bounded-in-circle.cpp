class Solution {
public:
    bool isRobotBounded(string instructions) {
        int dir = NORTH;
        int y = 0;
        int x = 0;

        for (int i = 0; i < 4; i++) {
            for (char instruction : instructions) {
                if (instruction == 'G') {
                    y += OFFSET[dir][0];
                    x += OFFSET[dir][1];
                }
                if (instruction == 'L') dir = (dir + 3) % 4;
                if (instruction == 'R') dir = (dir + 1) % 4;
            }
            if (y == 0 && x == 0) return true;
        }

        return false;
    }

private:
    const int NORTH = 0;
    const int OFFSET[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
};