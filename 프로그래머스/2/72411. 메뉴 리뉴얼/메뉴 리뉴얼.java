import java.util.*;

class Solution {
    Map<String, Integer> candidate = new HashMap<>();
    public String[] solution(String[] orders, int[] course) {
        
        ArrayList<String> answer_list = new ArrayList<>();
        for(int i = 0; i<course.length; i++){
            for(int j = 0; j<orders.length; j++){
                StringBuilder sb = new StringBuilder();
                char[] chars = orders[j].toCharArray();
                Arrays.sort(chars);
                String sorted = new String(chars);
                makeString(sorted, 0, sb, course[i], 0);
                
            }
            int max_num = 0;
            ArrayList<String> list = new ArrayList<>();
            for(String key : candidate.keySet()){
                if(max_num<candidate.get(key) && candidate.get(key)>=2){
                    max_num = candidate.get(key);
                    list.clear();
                    list.add(key);
                }
                else if(max_num == candidate.get(key)){
                    list.add(key);
                }
            }
            if(list.size()!=0){
                for(int k = 0; k<list.size(); k++){
                    answer_list.add(list.get(k));
                }
            }
            candidate.clear();
        }
        String[] answer = answer_list.toArray(new String[0]);
        Arrays.sort(answer);
        return answer;
    }
    public void makeString(String str, int idx, StringBuilder sb, int max_l, int l){
        if(max_l==l){
            candidate.put(sb.toString(), candidate.getOrDefault(sb.toString(), 0) + 1);
            return;
        }
        for(int i = idx; i<=str.length()-(max_l-l); i++){
            sb.append(str.charAt(i));
            makeString(str, i+1, sb, max_l, l+1);
            sb.deleteCharAt(sb.length()-1);
        }
    }
}