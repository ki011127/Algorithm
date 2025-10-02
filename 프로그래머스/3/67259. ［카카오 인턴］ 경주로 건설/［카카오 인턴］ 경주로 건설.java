import java.util.*;

class Solution {
    public int solution(int[][] board) {
        int n = board.length;
        int INF = Integer.MAX_VALUE;
        int[][][] dist = new int[n][n][4];
        int answer = INF;
        for(int[][] d1 : dist){
            for(int[] d2 : d1){
                Arrays.fill(d2,INF);
            }
        }
        
        int[] dx = {1,0,-1,0};
        int[] dy = {0,1,0,-1};
        
        PriorityQueue<Node> pq = new PriorityQueue<>();
        
        pq.offer(new Node(0,0,-1,0));
        
        while(pq.size()!=0){
            Node cur_node = pq.poll();
            if(cur_node.x==n-1 && cur_node.y==n-1){
                answer = Math.min(answer, cur_node.cost);
                continue;
            }
            
            for(int i = 0; i<4; i++){
                int nx = cur_node.x+dx[i];
                int ny = cur_node.y+dy[i];
                
                if(nx<0 || ny<0 || nx>=n || ny>=n){
                    continue;
                }
                if(board[ny][nx]==1){
                    continue;
                }
                
                int nc = cur_node.cost;
                if(cur_node.dir==-1 || i==cur_node.dir){
                    nc+=100;
                }
                else{
                    nc+=600;
                }
                if(dist[ny][nx][i]>nc){
                    dist[ny][nx][i]=nc;
                    pq.offer(new Node(nx,ny,i,nc));
                }
                
                
            }
            
        }
        
        
        return answer;
    }
    
    class Node implements Comparable<Node>{
        int x,y,dir,cost;
        
        public Node(int x, int y, int dir, int cost){
            this.x = x;
            this.y = y;
            this.dir = dir;
            this.cost = cost;
        }
        
        @Override
        public int compareTo(Node o){
            return this.cost-o.cost;
        }
    }
}