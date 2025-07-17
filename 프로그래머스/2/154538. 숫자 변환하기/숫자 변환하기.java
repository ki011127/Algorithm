class Solution {
    
    public int solution(int x, int y, int n) {
        int[] dp = new int[y+1];
        dp[x] = 1;
        for(int i = x+1; i<y+1; i++){
            int num = 1000000;
            if(i%2==0 && dp[i/2]!=0 && dp[i/2]!=1000000){
                num = Math.min(num, dp[i/2]+1);
            }
            if(i%3==0 && dp[i/3]!=0 && dp[i/3]!=1000000){
                num = Math.min(num, dp[i/3]+1);
            }
            if(i-n>0&& dp[i-n]!=0 && dp[i-n]!=1000000){
                num = Math.min(num, dp[i-n]+1);
            }
            
            dp[i] = num;
        }
        if(dp[y]==1000000){
            return -1;
        }
        else{
            return dp[y]-1;
        }
    }
}