import java.util.*;

class Solution {
    public int solution(String[] friends, String[] gifts) {
        Map<String, Integer> m = new HashMap<>();
        Map<String, Integer> gift_factor = new HashMap<>();
        
        for(int i = 0; i<gifts.length; i++){
            m.put(gifts[i], m.getOrDefault(gifts[i],0)+1);
            String[] fs = gifts[i].split(" ");
            gift_factor.put(fs[0], gift_factor.getOrDefault(fs[0],0)+1);
            gift_factor.put(fs[1], gift_factor.getOrDefault(fs[1],0)-1);
        }
        int answer = 0;
        
        for(int i = 0; i<friends.length; i++){
            int a = 0;
            for(int j = 0; j<friends.length; j++){
                if(i==j){
                    continue;
                }
                if(m.getOrDefault(friends[i]+" "+friends[j],0)>m.getOrDefault(friends[j]+" "+friends[i],0)){
                    a++;
                }
                else if(m.getOrDefault(friends[i]+" "+friends[j],0)==m.getOrDefault(friends[j]+" "+friends[i],0)){
                    if(gift_factor.getOrDefault(friends[i],0) > gift_factor.getOrDefault(friends[j], 0)){
                        a++;
                    }
                }
            }
            answer= Math.max(answer, a);
        }
        
        return answer;
    }
}