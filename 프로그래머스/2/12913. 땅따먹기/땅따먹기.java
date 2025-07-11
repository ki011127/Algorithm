import java.util.*;

class Solution {
    int solution(int[][] land) {
        int answer = 0;

        int[][] dp = new int[land.length][4];
        for(int i = 0; i<4; i++){
            dp[land.length-1][i] = land[land.length-1][i];
        }
        
        for(int i = land.length-2; i>=0; i--){
            for(int j = 0; j<4; j++){
                for(int k = 0; k<4; k++){
                    if(j==k){
                        continue;
                    }
                    int score = land[i][j]+dp[i+1][k];
                    if(dp[i][j]<score){
                        dp[i][j] = score;
                    }
                }
            }
        }
        
        for(int i = 0; i<4; i++){
            if(answer<dp[0][i]){
                answer = dp[0][i];
            }
        }

        return answer;
    }
}