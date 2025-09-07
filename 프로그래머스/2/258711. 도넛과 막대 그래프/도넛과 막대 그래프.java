class Solution {
    public int[] solution(int[][] edges) {
        int[] indegree = new int[1000001];
        int[] outdegree = new int[1000001];
        int max_v = 0;
        for(int i = 0; i<edges.length; i++){
            int out = edges[i][0];
            int in = edges[i][1];
            indegree[in] +=1;
            outdegree[out] +=1;
            max_v = Math.max(max_v, Math.max(in,out));
        }
        int add_v = 0;
        for(int i = 1; i<=max_v; i++){
            if(indegree[i]==0 && outdegree[i]>=2){
                add_v = i;
            }
        }
        for(int i = 0; i<edges.length; i++){
            if(indegree[i]==0 && outdegree[i]==0){
                indegree[i] = -1;
                outdegree[i] = -1;
            }
        }
        for(int i = 0; i<edges.length; i++){
            int out = edges[i][0];
            int in = edges[i][1];
            if(out == add_v && indegree[in]>0){
                indegree[in]--;
            }
        }
        
        int eight_graph = 0;
        int bar_graph = 0;
        for(int i = 1; i<=max_v; i++){
            if(indegree[i]==2 && outdegree[i]==2){
                eight_graph++;
            }
            if((indegree[i]==1 && outdegree[i]==0) || (indegree[i]==0 && outdegree[i]==0)){
                bar_graph++;
            }
        }
        int donut_graph = outdegree[add_v]-eight_graph-bar_graph;
        if(donut_graph<0){
            donut_graph = 0;
        }
        
        return new int[]{add_v, donut_graph, bar_graph, eight_graph};
    }
}