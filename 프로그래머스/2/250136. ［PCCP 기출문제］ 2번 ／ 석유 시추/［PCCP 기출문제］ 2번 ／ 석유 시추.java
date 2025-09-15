import java.util.*;

class Solution {
    int oil_count = 1;
    public int solution(int[][] land) {
        int answer = 0;
        int count = 1;
        int[][] land_1 = new int[land.length][land[0].length];
        System.out.println(land[0].length);
        Map<Integer, Integer> m = new HashMap<>();
        
        for(int i = 0; i<land.length; i++){
            for(int j = 0; j<land[0].length; j++){
                oil_count = 1;
                if(land[i][j]==1){
                    check(land, land_1, j, i, count);
                    m.put(count, oil_count);
                    count++;
                }
            }
        }
        
        for(int j = 0; j<land[0].length; j++){
            Map<Integer, Integer> map = new HashMap<>();
            int c= 0;
            for(int i = 0; i<land.length; i++){
                if(land_1[i][j]!=0 && map.getOrDefault(land_1[i][j],0)==0){
                    c+=m.get(land_1[i][j]);
                    map.put(land_1[i][j],1);
                }
            }
            answer = Math.max(answer,c);
        }
        
        return answer;
    }
    
    public void check(int[][] land, int[][] land_1, int cx, int cy, int count){
        int[] dx = {1,0,-1,0};
        int[] dy = {0,1,0,-1};
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{cx, cy});
        land[cy][cx] = 0;
        land_1[cy][cx] = count;

        while(!q.isEmpty()){
            int[] cur = q.poll();
            int x = cur[0], y = cur[1];
            for(int i=0;i<4;i++){
                int nx = x+dx[i], ny = y+dy[i];
                if(nx>=0 && nx<land[0].length && ny>=0 && ny<land.length && land[ny][nx]==1){
                    land[ny][nx] = 0;
                    land_1[ny][nx] = count;
                    oil_count++;
                    q.add(new int[]{nx, ny});
                }
            }
        }
    }
}