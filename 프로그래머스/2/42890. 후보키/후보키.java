import java.util.*;

class Solution {
    Set<HashSet<Integer>> set = new HashSet<>();
    
    public void dfs(int idx, ArrayList<Integer> idx_list, String[][] relation, int size){
        if(size==0){
            Set<String> candidate_key = new HashSet<>();
            
            for(int i = 0; i<relation.length; i++){
                StringBuilder sb = new StringBuilder();
                for(int j = 0; j<idx_list.size(); j++){
                    sb.append(relation[i][idx_list.get(j)]);
                }
                candidate_key.add(sb.toString());
            }
            if(relation.length==candidate_key.size()){
                HashSet<Integer> key = new HashSet<>(idx_list);
                for (HashSet<Integer> existingKey : set) {
                    if (key.containsAll(existingKey)) return;
                }
                set.add(key);
            }
            return;
        }
        for(int i = idx; i<relation[0].length; i++){
            if(relation[0].length-i>=size){
                idx_list.add(i);
                dfs(i+1, idx_list, relation, size-1);
                idx_list.remove(idx_list.size() - 1);
            }
        }
    }
    
    public int solution(String[][] relation) {
        
        for(int i = 1; i<=relation[0].length; i++){
            ArrayList<Integer> idx_list = new ArrayList<>();
            dfs(0, idx_list, relation, i);
        }
        return set.size();
    }
}