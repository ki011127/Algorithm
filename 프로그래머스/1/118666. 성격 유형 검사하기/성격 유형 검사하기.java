import java.util.*;

class Solution {
    public String solution(String[] survey, int[] choices) {
        StringBuilder sb = new StringBuilder();
        
        Map<String, Integer> m = new HashMap<>();

        for(int i = 0; i<survey.length; i++){
            String a = survey[i].substring(0,1);
            String b = survey[i].substring(1,2);
            int choice = choices[i];
            if(choice==1){
                m.put(a, m.getOrDefault(a,0)+3);
            }
            else if(choice==2){
                m.put(a, m.getOrDefault(a,0)+2);
            }
            else if(choice==3){
                m.put(a, m.getOrDefault(a,0)+1);
            }
            else if(choice==5){
                m.put(b, m.getOrDefault(b,0)+1);
            }
            else if(choice==6){
                m.put(b, m.getOrDefault(b,0)+2);
            }
            else if(choice==7){
                m.put(b, m.getOrDefault(b,0)+3);
            }
        }
        
        if(m.getOrDefault("R",0)>=m.getOrDefault("T",0)){
            sb.append("R");
        }
        else{
            sb.append("T");
        }
        if(m.getOrDefault("C",0)>=m.getOrDefault("F",0)){
            sb.append("C");
        }
        else{
            sb.append("F");
        }
        
        if(m.getOrDefault("J",0)>=m.getOrDefault("M",0)){
            sb.append("J");
        }
        else{
            sb.append("M");
        }
        
        if(m.getOrDefault("A",0)>=m.getOrDefault("N",0)){
            sb.append("A");
        }
        else{
            sb.append("N");
        }
        
        String answer = sb.toString();
        return answer;
    }
}