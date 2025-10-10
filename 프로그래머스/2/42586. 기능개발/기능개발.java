import java.util.*;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        int[] complete = new int[progresses.length];
        for(int i = 0; i<progresses.length; i++){
            complete[i] = (100-progresses[i])/speeds[i];
            if((100-progresses[i])%speeds[i]!=0){
                complete[i]++;
            }
        }

        ArrayList<Integer> list = new ArrayList<>();
        for(int i = 0; i<complete.length; i++){
            int c = complete[i];
            int idx = i+1;
            int count = 1;
            while(idx<complete.length && c>=complete[idx]){
                count++;
                idx++;
            }
            i = idx-1;
            list.add(count);
        }
        
        int[] answer = new int[list.size()];
        for(int i = 0; i<answer.length; i++){
            answer[i] = list.get(i);
        }
        return answer;
    }
}