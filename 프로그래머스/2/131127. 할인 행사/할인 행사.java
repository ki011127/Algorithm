import java.util.*;

class Solution {
    public int solution(String[] want, int[] number, String[] discount) {
        int answer = 0;
        Map<String, Integer> buy = new HashMap<String, Integer>();
        Map<String, Integer> want_buy = new HashMap<String, Integer>();
        for(int i = 0; i<want.length; i++){
            buy.put(want[i], number[i]);
            want_buy.put(want[i], 1);
        }
        
        for(int i = 0; i<10; i++){
            if(want_buy.getOrDefault(discount[i],0)==1){
                Integer num = buy.getOrDefault(discount[i], 0)-1;
                if(num==0){
                    buy.remove(discount[i]);
                }
                else{
                    buy.put(discount[i], num);
                }
            }
        }
        
        for(int i = 10; i<discount.length; i++){
            if(buy.size()==0){
                answer++;
            }

            if(want_buy.getOrDefault(discount[i],0)==1){
                Integer cur_discount = buy.getOrDefault(discount[i], 0)-1;
                if(cur_discount==0){
                    buy.remove(discount[i]);
                }
                else{
                    buy.put(discount[i], cur_discount);
                }
            }
            if(want_buy.getOrDefault(discount[i-10],0)==1){
                Integer past_discount = buy.getOrDefault(discount[i-10], 0)+1;
                if(past_discount==0){
                    buy.remove(discount[i-10]);
                }
                else{
                    buy.put(discount[i-10], past_discount);
                }
            }
        }
        if(buy.size()==0){
            answer++;
        }
        
        return answer;
    }
}