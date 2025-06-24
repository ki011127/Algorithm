import java.util.*;

class Solution {
    public int[] solution(int[] fees, String[] records) {
        Map<String, Integer> record_map = new TreeMap<>();
        Map<String, Integer> total_time = new TreeMap<>();
        
        for(int i = 0 ; i<records.length; i++){
            StringTokenizer st = new StringTokenizer(records[i], " ");
            String time = st.nextToken();
            StringTokenizer time_st = new StringTokenizer(time, ":");
            String car_num = st.nextToken();
            Integer hour = Integer.parseInt(time_st.nextToken());
            Integer minute = Integer.parseInt(time_st.nextToken());
            Integer m = hour*60+minute;
            if(record_map.containsKey(car_num)){
                Integer temp = m - record_map.get(car_num);
                if(total_time.containsKey(car_num)){
                    total_time.put(car_num, total_time.get(car_num)+temp);
                }
                else{
                    total_time.put(car_num,temp);
                }
                record_map.remove(car_num);
            }
            else{
                record_map.put(car_num, m);
            }
        }
        for(String c_num : record_map.keySet()){
            Integer temp = 23*60+59 - record_map.get(c_num);
            if(total_time.containsKey(c_num)){
                total_time.put(c_num, total_time.get(c_num)+temp);
            }
            else{
                total_time.put(c_num,temp);
            }
        }
        int[] answer = new int[total_time.size()];
        int i = 0;
        
        for(String c_num : total_time.keySet()){
            Integer a = (total_time.get(c_num)-fees[0]);
            if(a<0){
                a = 0;
            }
            Integer fee = fees[1] + (int)Math.ceil((double)a/fees[2])*fees[3];
            answer[i++] = fee;
        }
        
        return answer;
    }
}