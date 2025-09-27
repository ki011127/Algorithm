import java.util.*;

class Solution {
    int[][] group_id;
    int[][] visited;
    int count = 1;
    static int[] dx = {1, -1, 0, 0};
    static int[] dy = {0, 0, 1, -1};
    
    public int[] solution(int m, int n, int[][] picture) {
        
        group_id = new int[m][n];
        visited = new int[m][n];
        
        int id = 0;
        int max_area_count = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(visited[i][j]==0 && picture[i][j]!=0){
                    bfs(m,n,j,i,id, picture);
                    if(max_area_count<count){
                        max_area_count = count;
                    }
                    id++;
                }
                count = 1;
            }
        }
        
        
        int[] answer = new int[2];
        answer[0] = id;
        answer[1] = max_area_count;
        return answer;
    }
    
    void bfs(int m, int n, int x, int y, int id, int[][] picture){
        visited[y][x] = 1;
        group_id[y][x] = id;
        int area = picture[y][x];
        Deque<int[]> q = new ArrayDeque<>();
        q.add(new int[]{x,y});
        
        while(q.size()!=0){
            int[] cur = q.poll();
            int cx = cur[0];
            int cy = cur[1];
            for(int i = 0; i<4; i++){
                int nx = cx+dx[i];
                int ny = cy+dy[i];
                if(nx>=0 && ny>=0 && nx<n && ny<m && visited[ny][nx]==0 && area==picture[ny][nx]){
                    count++;
                    q.add(new int[]{nx,ny});
                    visited[ny][nx] = 1;
                    group_id[ny][nx] = id;
                }
            }
        }
        
        
    }
}