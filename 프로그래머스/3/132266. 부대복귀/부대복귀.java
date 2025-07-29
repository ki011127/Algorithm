import java.util.*;

class Solution {
    List<List<Node>> graph = new ArrayList<>();
    int dist[];
    
    public void dij(int start){
        PriorityQueue<Node> pq = new PriorityQueue<>();
        dist[start] = 0;
        pq.add(new Node(start, 0));
        
        while(!pq.isEmpty()){
            Node cur = pq.poll();
            
            if(dist[cur.index]<cur.cost){
                continue;
            }
            for(Node next : graph.get(cur.index)){
                int cost = dist[cur.index] + next.cost;
                if(cost<dist[next.index]){
                    dist[next.index] = cost;
                    pq.add(new Node(next.index, cost));
                }
            }
        }
    }
    
    public int[] solution(int n, int[][] roads, int[] sources, int destination) {
        int[] answer = new int[sources.length];
        dist = new int[n+1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        
        for(int i = 0; i<=n; i++){
            graph.add(new ArrayList<>());
        }
        
        for(int i = 0; i<roads.length; i++){
            graph.get(roads[i][0]).add(new Node(roads[i][1], 1));
            graph.get(roads[i][1]).add(new Node(roads[i][0], 1));
        }
        dij(destination);
        for(int i = 0; i<sources.length; i++){
            if(dist[sources[i]]==Integer.MAX_VALUE){
                answer[i] = -1;
            }
            else{
                answer[i] = dist[sources[i]];
            }
        }
        return answer;
    }
    
    
    public class Node implements Comparable<Node>{
        int index;
        int cost;
        
        Node(int index, int cost){
            this.index = index;
            this.cost = cost;
        }
        
        @Override
        public int compareTo(Node o){
            return this.cost - o.cost;
        }
    }
}