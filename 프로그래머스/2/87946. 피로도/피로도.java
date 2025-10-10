class Solution {
    int answer = 0;
    int[] visited = new int[8];
    public int solution(int k, int[][] dungeons) {
        dfs(k, dungeons, 0);
        return answer;
    }
    
    public void dfs(int cur_t, int[][] dungeons, int count){
        answer = Math.max(answer, count);
        for(int i = 0; i<dungeons.length; i++){
            if(visited[i]==0 && cur_t>=dungeons[i][0]){
                visited[i] = 1;
                dfs(cur_t-dungeons[i][1], dungeons, count+1);
                visited[i] = 0;
            }
        }
        
    }
}