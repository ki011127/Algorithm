class Solution {
    public int solution(int[][] triangle) {
        
        int[][] dp = new int[triangle.length][triangle.length];

        for(int i = 0; i<triangle.length; i++){
            dp[triangle.length-1][i] = triangle[triangle.length-1][i];
        }
        for(int i = triangle.length-2; i>=0; i--){
            for(int j = 0; j<=i; j++){
                if(dp[i+1][j]>dp[i+1][j+1]){
                    dp[i][j] = triangle[i][j]+dp[i+1][j];
                }
                else{
                    dp[i][j] = triangle[i][j]+dp[i+1][j+1];
                }
            }
        }
        int answer = dp[0][0];
        return answer;
    }
}