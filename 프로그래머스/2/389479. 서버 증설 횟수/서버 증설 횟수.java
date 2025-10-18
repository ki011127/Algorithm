class Solution {
    public int solution(int[] players, int m, int k) {
        int answer = 0;
        int cur_server = 0;
        int[] add_server = new int[24];
        for(int i = 0; i<players.length; i++){
            if(i>=k){
                cur_server-=add_server[i-k];
            }
            if((cur_server+1)*m<=players[i]){
                int s = players[i]/m;
                
                add_server[i] = s-cur_server;
                answer += add_server[i];
                cur_server = s;
            }
        }
        return answer;
    }
}