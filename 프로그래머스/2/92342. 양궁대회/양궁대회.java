import java.util.*;

class Solution {
    int[] answer = new int[11];
    int max_score = 0;
    public int[] solution(int n, int[] info) {
        int[] r_info = new int[11];
        dfs(n, info, 0, 0, 0, r_info);
        for(int i =0; i<11; i++){
            if(answer[i]!=0){
                return answer;
            }
        }
        int[] a = {-1};
        return a;
    }
    void dfs(int r_arrow, int[] info, int a_score, int r_score, int idx, int[] r_info){
        if(idx==10){
            if(r_score==a_score){
                return;
            }
            if(r_arrow>0){
                r_info[idx]=r_arrow;
            }
            
            if(r_score-a_score>max_score){
                max_score=r_score-a_score;
                answer = Arrays.copyOf(r_info, r_info.length);
            }
            if(r_score-a_score==max_score){
                for (int i = 10; i >= 0; i--) {
                    if (r_info[i] > answer[i]) {
                        answer = Arrays.copyOf(r_info, r_info.length);
                        break;
                    } else if (r_info[i] < answer[i]) {
                        break;
                    }
                }
            }
            r_info[idx] = 0;
            return;
        }
        
        if(r_arrow>info[idx]){
            r_info[idx]=info[idx]+1;
            dfs(r_arrow-(info[idx]+1), info, a_score, r_score+(10-idx), idx+1, r_info);
            r_info[idx]=0;
        }
        
        if(info[idx]>0){
            dfs(r_arrow, info, a_score+(10-idx), r_score, idx+1, r_info);
        }
        else{
            dfs(r_arrow, info, a_score, r_score, idx+1, r_info);
        }
        
        
        
        
    }
}