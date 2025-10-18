import java.util.*;

class Solution {
    
    public int solution(int[][] info, int n, int m) {
        int inf = 1000000000;
        int[] dp = new int[m];
        Arrays.fill(dp, inf);
        dp[0] = 0;
        
        for(int[] item : info){
            int a = item[0];
            int b = item[1];
            int[] new_dp = new int[m];
            Arrays.fill(new_dp, inf);
            
            for(int i = 0; i<m; i++){
                if(dp[i]==inf){
                    continue;
                }
                int next_a = dp[i]+a;
                int next_b = i;
                if(next_a<new_dp[next_b]){
                    new_dp[next_b]=next_a;
                }
                
                next_a = dp[i];
                next_b = i+b;
                if(next_b<m && next_a<new_dp[next_b]){
                    new_dp[next_b] = next_a;
                }
            }
            dp = new_dp;
        }
        
        int answer = inf;
        for (int b = 0; b < m; b++) {
            if (dp[b] < n) {
                answer = Math.min(answer, dp[b]);
            }
        }

        return answer == inf ? -1 : answer;
        
    }
}