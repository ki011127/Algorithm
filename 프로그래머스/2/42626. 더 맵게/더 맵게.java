import java.util.*;

class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        PriorityQueue<Integer> min_heap = new PriorityQueue<>();
        for(int i = 0; i<scoville.length; i++){
            min_heap.add(scoville[i]);
        }
        int cur_k = -1;
        while(min_heap.peek()<K && min_heap.size()>=2){
            int min = min_heap.peek();
            cur_k = min_heap.poll() + min_heap.poll()*2;
            if(cur_k<=min){
                return -1;
            }
            min_heap.add(cur_k);
            answer++;
        }
        if(min_heap.peek()<K){
            return -1;
        }
        return answer;
    }
}