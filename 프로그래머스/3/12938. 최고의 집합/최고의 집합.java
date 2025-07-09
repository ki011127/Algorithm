class Solution {
    public int[] solution(int n, int s) {
        
        if(n>s){
            int[] answer = new int[1];
            answer[0] = -1;
            return answer;
        }
        int num = s/n;
        int temp = s;
        int[] answer = new int[n];
        for(int i = 0; i<n; i++){
            answer[i] = num;
            temp-=num;
        }
        while(temp!=0){
            for(int i = n-1; i>=0; i--){
                if(temp==0){
                    break;
                }
                answer[i] +=1;
                temp-=1;
            }
        }
        return answer;
    }
}