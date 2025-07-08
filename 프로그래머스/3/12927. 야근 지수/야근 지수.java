import java.util.*;

class Solution {
    public long solution(int n, int[] works) {
        long answer = 0;
        PriorityQueue<Integer> max_heap = new PriorityQueue<>(Collections.reverseOrder());
        for(int i = 0; i<works.length; i++){
            max_heap.add(works[i]);
        }
        while(n!=0){
            
            int max = max_heap.poll();
            if(max==0){
                break;
            }
            int n_max = max_heap.peek();
            if(max-n_max>0){
                int temp = Math.min(max-n_max, n);
                max_heap.add(max-temp);
                n-=temp;
            }
            else if(max-n_max==0){
                n -=1;
                max_heap.add(max-1);
            }
        }
        while(!max_heap.isEmpty()){
            int work = max_heap.poll();
            answer+=(work*work);
        }
        return answer;
    }
}