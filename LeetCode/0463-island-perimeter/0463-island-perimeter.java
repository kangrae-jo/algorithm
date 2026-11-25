
class Solution {

    private static int[][] OFFSET = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
    private static int EMPTY = 0;
    private static int WALL = 1;

    public int islandPerimeter(int[][] grid) {
        int N = grid.length;
        int M = grid[0].length;

        int answer = 0;
        boolean[][] visited = new boolean[N][M];
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (grid[y][x] == WALL && !visited[y][x]) {
                    answer += bfs(grid, y, x, visited);
                }
            }
        }

        return answer;
    }

    private int bfs(int[][] grid, int y, int x, boolean[][] visited) {
        Deque<int[]> q = new ArrayDeque<>(); 
        q.push(new int[]{y, x});
        visited[y][x] = true;

        int answer = 0;
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int cY = cur[0];
            int cX = cur[1];

            for (int dir = 0; dir < 4; dir++) {
                int nY = cY + OFFSET[dir][0];
                int nX = cX + OFFSET[dir][1];

                if (!isIn(nY, nX, grid.length, grid[0].length) || grid[nY][nX] == EMPTY) {
                    answer++;
                } else if (!visited[nY][nX]) {
                    q.push(new int[]{nY, nX});
                    visited[nY][nX] = true;
                }
            }
        }

        return answer;
    }

    private boolean isIn(int y, int x, int N, int M) {
        return 0 <= y && y < N && 0 <= x && x < M;
    }
}
