import java.util.*;

class Solution {
    int flag = 0;
    int[] is_visit;
    String[] temp_ans;
    public String[] solution(String[][] tickets) {
        String[] answer = new String[tickets.length+1];
        Arrays.sort(tickets, (a, b) -> {
            if (a[0].equals("ICN") && !b[0].equals("ICN")) {
                return -1;
            } else if (!a[0].equals("ICN") && b[0].equals("ICN")) {
                return 1;
            }
            else if(a[0].equals("ICN") && b[0].equals("ICN")){
                return a[1].compareTo(b[1]);
            }
            else{
                if(!a[0].equals(b[0])){
                    return a[0].compareTo(b[0]);
                }
                else{
                    return a[1].compareTo(b[1]);
                }
            }
        });
        temp_ans = new String[tickets.length+1];
        is_visit = new int[tickets.length];
        for(int i = 0; i<tickets.length; i++){
            is_visit[i] = 1;
            answer[0] = tickets[i][0];
            solve(tickets[i][0], tickets[i][1], tickets, answer, 1);
            is_visit[i] = 0;
            if(flag == 1){
                return answer;
            }
        }
        
        return answer;
    }
    public void solve(String dep, String dest, String[][] tickets, String[] answer, int depth){
        if(depth+1 == answer.length){
            answer[depth] = dest;
            flag = 1;
            return;
        }
        if(flag == 1){
            return;
        }
        for(int i = 0; i<tickets.length; i++){
            if(is_visit[i]==0 && tickets[i][0].equals(dest)){
                answer[depth] = dest;
                is_visit[i] = 1;
                
                solve(tickets[i][0], tickets[i][1], tickets, answer, depth+1);
                is_visit[i] = 0;
            }
        }
    }
}