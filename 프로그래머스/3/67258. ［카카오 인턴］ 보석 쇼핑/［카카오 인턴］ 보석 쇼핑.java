import java.util.*;

class Solution {
    public int[] solution(String[] gems) {
        int[] answer = {0,gems.length-1};
        Set<String> s = new HashSet<>(Arrays.asList(gems));
        int kinds_nums = s.size();
        
        Map<String, Integer> m = new HashMap<>();
        
        int left = 0;
        
        for(int right = 0; right<gems.length; right++){
            m.put(gems[right], m.getOrDefault(gems[right],0)+1);
            
            while(m.size()==kinds_nums){
                if(right-left<answer[1]-answer[0]){
                    answer[1] = right;
                    answer[0] = left;
                }
                m.put(gems[left], m.get(gems[left])-1);
                if(m.get(gems[left])==0){
                    m.remove(gems[left]);
                }
                left++;
            }
        }
        
        
        
        
        answer[0]+=1;
        answer[1]+=1;
        return answer;
    }
}