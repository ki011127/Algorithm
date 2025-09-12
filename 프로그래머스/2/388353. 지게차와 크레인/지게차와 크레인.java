import java.util.*;

class Solution {
    int h;
    int w;
    public int solution(String[] storage, String[] requests) {
        String[] storage_backup = Arrays.copyOf(storage, storage.length);
        h = storage.length;
        w = storage[0].length();
        int answer = h*w;
        for(int i = 0; i<requests.length; i++){
            char target = requests[i].charAt(0);
            if(requests[i].length() == 1){
                for(int n = 0; n<storage.length; n++){
                    for(int m = 0; m<storage[n].length(); m++){
                        if(target == storage[n].charAt(m)){
                            boolean[][] visited = new boolean[h][w];
                            if(dfs(storage, m, n, visited)){
                                StringBuilder sb = new StringBuilder(storage_backup[n]);
                                sb.setCharAt(m,'0');
                                storage_backup[n] = sb.toString();
                                answer--;
                            }
                        }
                    }
                }
            }
            else{
                for(int n = 0; n<storage.length; n++){
                    for(int m = 0; m<storage[n].length(); m++){
                        if(target == storage[n].charAt(m)){
                            StringBuilder sb = new StringBuilder(storage_backup[n]);
                            sb.setCharAt(m,'0');
                            storage_backup[n] = sb.toString();
                            answer--;
                        }
                    }
                }
            }
            storage = Arrays.copyOf(storage_backup, storage_backup.length);
        }
        
        return answer;
    }
    
    boolean dfs(String[] storage, int cm, int cn, boolean[][] visited){
        if(cn==0 || cn==h-1 || cm==0 || cm==w-1){
            return true;
        }
        boolean result=false;
        int[] dm = {1,0,-1,0};
        int[] dn = {0,1,0,-1};
        for(int i = 0; i<4; i++){
            int nm = cm+dm[i];
            int nn = cn+dn[i];
            if(nm>=0 && nm<w && nn>=0 && nn<h && storage[nn].charAt(nm)=='0' && visited[nn][nm]==false){
                visited[nn][nm] = true;
                result =  dfs(storage, nm,nn,visited);
                if(result){
                    return result;
                }
            }
        }
        return result;
    }
}