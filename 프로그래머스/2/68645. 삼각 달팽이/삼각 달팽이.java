class Solution {
    public int[] solution(int n) {
        int[] answer = new int[n*(n+1)/2];
        int[][] m = new int[n][n];
        int i = -1;
        int j = 0;
        int f = n;
        int flag = 0;
        int num = 1;
        while(num<=n*(n+1)/2){
            int count = 0;
            while(count<f){
                
                if(flag ==0){
                    i++;
                }
                else if(flag == 1){
                    j++;
                }
                else{
                    i--;
                    j--;
                }
                m[i][j] = num;
                num++;
                count++;
            }
            f--;
            if(flag==0){
                flag = 1;
            }
            else if(flag==1){
                flag =2;
            }
            else{
                flag = 0;
            }
        }
        num = 0;
        for(i = 0; i<n; i++){
            for(j = 0; j<=i; j++){
                answer[num++] = m[i][j];
            }
        }
        return answer;
    }
}