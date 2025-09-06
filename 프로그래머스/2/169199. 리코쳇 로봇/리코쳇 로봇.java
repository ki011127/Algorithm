import java.util.*;

class Solution {
    static int[] dx = {1, -1, 0, 0};
    static int[] dy = {0, 0, 1, -1};
    public int solution(String[] board) {
        int answer = 0;
        boolean[][] visited = new boolean[board.length][board[0].length()];
        int start_x = 0;
        int start_y = 0;
        for(int i =0 ;i<board.length; i++){
            for(int j =0; j<board[0].length(); j++){
                if(board[i].charAt(j)=='R'){
                    start_x = j;
                    start_y = i;
                }
            }
        }

        Deque<int[]> deque = new ArrayDeque<>();
        
        deque.addLast(new int[]{start_x, start_y, 0});
        visited[start_y][start_x] = true;
        while (!deque.isEmpty()) {
            int[] cur = deque.pollFirst();
            int cx = cur[0], cy = cur[1], c_times = cur[2];

            for (int i = 0; i < 4; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                while(nx >= 0 && ny >= 0 && nx < board[0].length() && ny < board.length && board[ny].charAt(nx) != 'D'){
                    nx += dx[i];
                    ny += dy[i];
                }
                nx = nx-dx[i];
                ny = ny-dy[i];
                if(board[ny].charAt(nx)=='G'){
                    return c_times+1;
                }
                if (!visited[ny][nx]) {
                    visited[ny][nx] = true;
                    deque.addLast(new int[]{nx, ny, c_times+1});
                }
            }
        }
        
        return -1;
    }
    
}