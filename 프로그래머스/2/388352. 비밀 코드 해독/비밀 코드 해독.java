class Solution {
    int answer = 0;
    public int solution(int n, int[][] q, int[] ans) {
        int[] comb = new int[5];
        combination(n, 0, 1, q, ans, comb);
        
        
        return answer;
    }
    
    public void combination(int n, int count, int cur, int[][] q, int[] ans, int[] comb){
        if(count==5){
            System.out.println();
            for(int i = 0; i<q.length; i++){
                int cnt = 0;
                for(int j = 0; j<5; j++){
                    for(int k = 0; k<5; k++){
                        if(q[i][j]==comb[k]){
                            cnt++;
                            break;
                        }
                    }
                }
                if(cnt!=ans[i]){
                    return;
                }
            }
            answer++;
            return;
        }
        
        for(int i = cur; i<=n; i++){
            comb[count] = i;
            combination(n, count+1, i+1, q, ans, comb);
        }
    }
}