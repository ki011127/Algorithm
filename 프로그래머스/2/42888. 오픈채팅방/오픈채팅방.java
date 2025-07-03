import java.util.*;

class Solution {
    public String[] solution(String[] record) {
        Map<String, String> id_nickname = new HashMap<>();
        ArrayList<String> list = new ArrayList<>();
        for(int i = 0; i<record.length; i++){
            String[] parts = record[i].split(" ");
            if(parts[0].equals("Enter")){
                id_nickname.put(parts[1],parts[2]);
                list.add(parts[1]+" in");
            }
            else if(parts[0].equals("Leave")){
                list.add(parts[1]+" out");
            }
            else if(parts[0].equals("Change")){
                id_nickname.put(parts[1],parts[2]);
            }
        }
        String[] answer = new String[list.size()];
        for(int i = 0; i<answer.length; i++){
            String parts[] = list.get(i).split(" ");
            if(parts[1].equals("in")){
                answer[i] = id_nickname.get(parts[0])+"님이 들어왔습니다.";
            }
            else{
                answer[i] = id_nickname.get(parts[0])+"님이 나갔습니다.";
            }
        }
        return answer;
    }
}