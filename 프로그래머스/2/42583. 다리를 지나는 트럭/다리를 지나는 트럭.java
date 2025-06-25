import java.util.*;
import java.io.*;

class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        Deque<Integer> bridge = new ArrayDeque<>();
        Map<Integer, Integer> map = new HashMap<>();
        int time = 1;
        int index = 0 ;
        bridge.addLast(index);
        map.put(index, time);
        int cur_weight = truck_weights[index];
        if(index == truck_weights.length-1){
            time+=bridge_length;
            return time;
        }
        index++;
        time++;
        while(bridge.size()!=0){
            if(bridge_length==time-map.get(bridge.peekFirst())){
                cur_weight -= truck_weights[bridge.removeFirst()];
            }
            if(weight>=cur_weight+truck_weights[index]){
                if(index == truck_weights.length-1){
                    time+=bridge_length;
                    break;
                }
                bridge.addLast(index);
                map.put(index, time);
                cur_weight += truck_weights[index++];
            }
            time++;
        }
        return time;
    }
}