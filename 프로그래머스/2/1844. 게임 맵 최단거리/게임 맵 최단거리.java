import java.util.*;
import java.io.*;

class Solution {
    static int[] dx = {-1,1,0,0};
    static int[] dy = {0,0,-1,1}; // 상하좌우 이동 방향
    static int startX, startY = 0; // 초기 위치 설정

    public int solution(int[][] maps) {
        int answer = 0;
        int n = maps.length; // y 최대길이
        int m = maps[0].length; // x 최대길이

        boolean[][] visited = new boolean[n][m]; // 방문여부 저장소
        int[][] distance = new int[n][m]; // 누적 거리 정보 저장소
        distance[startX][startY] = 1; // 초기위치의 distacne는 1로 초기화

        Queue<int[]> queue = new LinkedList<>(); // 다음에 살펴볼 위치 정보 저장소
        queue.offer(new int[]{startX, startY}); // 초기위치 정보를 처음에 넣어둠
        while(!queue.isEmpty()){
            int[] current = queue.poll();
            int x = current[0];
            int y = current[1]; // x,y는 현재 위치

            for(int i = 0 ; i<4 ; i++){ // 현재 위치의 상하좌우를 살펴봄
                int nextX = x + dx[i];
                int nextY = y + dy[i];

                if(nextX < 0 || nextY < 0 || nextX >=n || nextY >= m) continue; // map에 벗어나면 탈락
                if(visited[nextX][nextY] || maps[nextX][nextY] == 0) continue; // 이미 방문했거나, 벽이라면 탈락

                visited[nextX][nextY] = true; // 방문 처리
                distance[nextX][nextY] = distance[x][y] + 1; // 해당 위치의 거리 정보 설정
                queue.offer(new int[]{nextX, nextY}); // 해당 위치를 다음에 살펴볼 위치로 넣어주기
            }
        }

        return distance[n-1][m-1] == 0 ? -1 : distance[n-1][m-1]; // 도착지의 거리가 0이면 이동 불가능한 경우이므로 -1 반환
    }
}