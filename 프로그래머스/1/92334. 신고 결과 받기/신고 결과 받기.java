import java.util.*;

class Solution {
    public int[] solution(String[] id_list, String[] report, int k) {
        int[] answer = new int[id_list.length];
        Map<String, Integer> report_m = new HashMap<>();
        Map<String, Integer> report_num = new HashMap<>();
        Map<String, List<String>> m = new HashMap<>();
        
        for(int i = 0; i<report.length; i++){
            if(report_m.containsKey(report[i])){
                continue;
            }
            report_m.put(report[i],1);
            String[] r = report[i].split(" ");
            List<String> list = m.getOrDefault(r[0], new ArrayList<>());
            list.add(r[1]);
            m.put(r[0], list);
            report_num.put(r[1], report_num.getOrDefault(r[1], 0)+1);
        }
        
        for(int i = 0; i<id_list.length; i++){
            int count = 0;
            List<String> list = m.getOrDefault(id_list[i], new ArrayList<>());
            for(int j = 0; j<list.size(); j++){
                if(report_num.getOrDefault(list.get(j), 0) >= k){
                    count++;
                }
            }
            answer[i] = count;
        }
        
        return answer;
    }
}