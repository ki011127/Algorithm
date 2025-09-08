import java.util.*;

class Solution {
    public long solution(int cap, int n, int[] deliveries, int[] pickups) {
        long answer = 0;
        PriorityQueue<Integer> deliveries_max_heap = new PriorityQueue<>(Comparator.reverseOrder());
        PriorityQueue<Integer> pickups_max_heap = new PriorityQueue<>(Comparator.reverseOrder());
        for(int i = 0; i<n; i++){
            if(deliveries[i]!=0){
                deliveries_max_heap.add(i);
            }
            if(pickups[i]!=0){
                pickups_max_heap.add(i);
            }
        }
        
        while(deliveries_max_heap.size()!=0 || pickups_max_heap.size()!=0){
            int dist = 0;
            if(deliveries_max_heap.size()!=0){
                int house = deliveries_max_heap.peek();
                dist = house;
                int d = deliveries[house];
                while(cap>d){
                    deliveries[house] = 0;
                    deliveries_max_heap.poll();
                    if(deliveries_max_heap.size()!=0){
                        house = deliveries_max_heap.peek();
                        d += deliveries[house];
                    }
                    else{
                        break;
                    }
                }
                deliveries[house]=d-cap;
                if(d-cap<=0){
                    deliveries[house] = 0;
                    deliveries_max_heap.poll();
                }
            }
            if(pickups_max_heap.size()!=0){
                int house = pickups_max_heap.peek();
                dist = Math.max(house,dist);
                int d = pickups[house];
                while(cap>d){
                    pickups[house] = 0;
                    pickups_max_heap.poll();
                    if(pickups_max_heap.size()!=0){
                        house = pickups_max_heap.peek();
                        d += pickups[house];
                    }
                    else{
                        break;
                    }
                }
                pickups[house]=d-cap;
                if(d-cap<=0){
                    pickups[house] = 0;
                    pickups_max_heap.poll();
                }
            }
            answer+=((dist+1)*2);
        }
        
        
        
        return answer;
    }
}