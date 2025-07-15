import java.util.*;

class Solution {
    public long solution(int[] weights) {
        long answer = 0;
        Map<Integer, Integer> hashMap = new HashMap<>();
        for(int i = 0; i<weights.length; i++){
            hashMap.put(weights[i],hashMap.getOrDefault(weights[i],0)+1);
        }
        for(int i = 0; i<weights.length; i++){
            for(int factor = 2; factor<5; factor++){
                int num = weights[i]*factor;
                for(int j = 2; j<5; j++){
                    if(num%j==0){
                        if(hashMap.get(num/j)!=null){
                            if(num/j==weights[i] && j==factor){
                                continue;
                            }
                            answer+=(hashMap.get(num/j));
                        }
                    }
                }
            }
            answer+=(hashMap.get(weights[i])-1);
        }
        return answer/2;
    }
}