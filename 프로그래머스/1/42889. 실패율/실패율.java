import java.util.*;

class Solution {
    public int[] solution(int N, int[] stages) {
        int[] challenge_stage = new int[N+2];
        int[] sum_s = new int[N+2];
        int[] answer = new int[N];
        PriorityQueue<Fail> pq = new PriorityQueue<>();
        int num = stages.length;
        
        for(int stage : stages){
            challenge_stage[stage]++;
        }
        sum_s[1] = num;
        for(int i = 2; i<N+2; i++){
            sum_s[i] = sum_s[i-1]-challenge_stage[i-1];
        }
        
        for(int i =1; i<N+1; i++){
            double fail;
            if(challenge_stage[i]==0){
                fail = 0;
            }
            else{
                fail = (double)challenge_stage[i]/sum_s[i];
            }
            pq.add(new Fail(i, fail));
        }
        int i = 0;
        while(pq.size()!=0){
            answer[i++] = pq.poll().stage;
        }
        
        return answer;
    }
    
    public class Fail implements Comparable<Fail>{
        int stage;
        double fail;
        
        public Fail(int stage, double fail){
            this.stage = stage;
            this.fail = fail;
        }
        
        @Override
        public int compareTo(Fail o){
            if(this.fail==o.fail){
                return this.stage-o.stage;
            }
            else{
                return Double.compare(o.fail, this.fail);
            }
        }
    }
}