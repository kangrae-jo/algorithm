
class Solution {

    private static int[][] OFFSET = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
    private static int EMPTY = 0;
    private static int WALL = 1;

    public int islandPerimeter(int[][] grid) {
        int N = grid.length;
        int M = grid[0].length;

        int answer = 0;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (grid[y][x] == WALL) {
                    for (int dir = 0; dir < 4; dir++) {
                        int nY = y + OFFSET[dir][0];
                        int nX = x + OFFSET[dir][1];

                        if (!isIn(nY, nX, grid.length, grid[0].length) || grid[nY][nX] == EMPTY) {
                            answer++;
                        }
                    }
                }
            }
        }

        return answer;
    }

    private boolean isIn(int y, int x, int N, int M) {
        return 0 <= y && y < N && 0 <= x && x < M;
    }
}
