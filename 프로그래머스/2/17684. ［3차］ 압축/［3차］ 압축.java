import java.util.*;

class Solution {
    public int[] solution(String msg) {
        Map<String, Integer> dict = new HashMap<>();
        char a = 'A';
        for(char c = 'A'; c<='Z'; c++){
            dict.put(String.valueOf(c),(int)c-64);
        }
        int count = 27;
        ArrayList<Integer> list = new ArrayList<>();
        
        for(int i = 0; i<msg.length(); i++){
            StringBuilder sb = new StringBuilder();
            sb.append(msg.charAt(i));
            
            while(dict.getOrDefault(sb.toString(),0)!=0){
                i++;
                if(i==msg.length()){
                    break;
                }
                sb.append(msg.charAt(i));
            }
            if(!dict.containsKey(sb.toString())){
                dict.put(sb.toString(),count++);
            }
            if(i<msg.length()){
                sb.deleteCharAt(sb.length()-1);
            }
            list.add(dict.get(sb.toString()));
            i--;
        }
        
        
        int[] answer = new int[list.size()];
        
        for(int i =0; i<answer.length; i++){
            answer[i] = list.get(i);
        }
        return answer;
    }
}