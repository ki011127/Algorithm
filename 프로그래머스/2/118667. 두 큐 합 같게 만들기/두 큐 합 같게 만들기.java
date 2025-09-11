import java.util.*;

class Solution {
    public int solution(int[] queue1, int[] queue2) {
        int answer = -1;
        long total = 0;
        long q1_total = 0;
        long q2_total = 0;
        
        Deque<Integer> dq1 = new ArrayDeque<>();
        Deque<Integer> dq2 = new ArrayDeque<>();
        for(int q1 : queue1){
            q1_total+=q1;
            dq1.addLast(q1);
        }
        for(int q2 : queue2){
            q2_total+=q2;
            dq2.addLast(q2);
        }
        
        if(q1_total==q2_total){
            return 0;
        }
        
        total = q1_total+q2_total;
        int count = 0;
        while(count<=queue1.length*3){
            count++;
            if(q1_total>q2_total){
                int num = dq1.pollFirst();
                q1_total-=num;
                q2_total+=num;
                dq2.addLast(num);
            }
            else if(q1_total<q2_total){
                int num = dq2.pollFirst();
                q2_total-=num;
                q1_total+=num;
                dq1.addLast(num);
            }
            
            if(q1_total==q2_total){
                return count;
            }
            
        }
        
        return answer;
    }
}