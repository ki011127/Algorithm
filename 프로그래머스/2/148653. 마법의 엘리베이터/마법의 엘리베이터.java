class Solution {
    public int solution(int storey) {
        int answer = 0;
        while(storey>10){
            int num = storey%10;
            if(num>5){
                answer+=(10-num);
                storey = storey/10+1;
            }
            else if(num<5){
                answer+=num;
                storey /=10;
            }
            else{
                if(storey/10%10<5){
                    answer+=num;
                    storey /=10;
                }
                else{
                    answer+=num;
                    storey = storey/10+1;
                }
            }
        }
        return answer+Math.min(storey, 10-storey+1);
    }
}