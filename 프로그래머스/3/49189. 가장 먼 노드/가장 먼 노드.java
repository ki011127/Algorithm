import java.util.*;

class Solution {
    class Node implements Comparable<Node>{
        int index;
        int cost;
        Node(int index, int cost){
            this.index = index;
            this.cost = cost;
        }
        @Override
        public int compareTo(Node o){
            return this.cost-o.cost;
        }
    }
    
    int[] dist;
    List<List<Node>> graph;
    
    public int solution(int n, int[][] edge) {
        int INF = Integer.MAX_VALUE;
        graph = new ArrayList<>();
        for(int i = 0; i<=n; i++){
            graph.add(new ArrayList<>());
        }
        
        dist = new int[n+1];
        Arrays.fill(dist, INF);
        
        for(int i = 0; i<edge.length; i++){
            graph.get(edge[i][0]).add(new Node(edge[i][1], 1));
            graph.get(edge[i][1]).add(new Node(edge[i][0], 1));
        }
        
        dijkstra(1);
        List<Integer> min_dist = new ArrayList<>();
        int max = 1;
        for(int i = 1; i<n+1; i++){
            if(dist[i]>max){
                max = dist[i];
                min_dist.clear();
            }
            if(dist[i]==max){
                min_dist.add(i);
            }
        }
        return min_dist.size();
    }
    
    public void dijkstra(int start){
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.add(new Node(start, 0));
        dist[start] = 0;
        
        while(pq.size()!=0){
            Node cur = pq.poll();
            if(dist[cur.index]<cur.cost){
                continue;
            }
            for(Node next : graph.get(cur.index)){
                int new_cost = cur.cost + next.cost;
                if(new_cost<dist[next.index]){
                    dist[next.index] = new_cost;
                    pq.add(new Node(next.index, new_cost));
                }
            }
        }
    }
}