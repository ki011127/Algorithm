import java.util.*;

class Solution {
    public String[] solution(String[] files) {
        String[] answer = new String[files.length];
        File[] file_arr = new File[files.length];
        
        for(int i = 0; i<files.length; i++){
            int idx = 0;
            String file = files[i];
            char c = file.charAt(idx);
            while(!Character.isDigit(c)){
                c = file.charAt(++idx);
            }
            String head = file.substring(0,idx);
            int idx2 = idx;
            c = file.charAt(idx2);
            while(Character.isDigit(c) && idx2-idx<5 && idx2<file.length()){
                if(++idx2==file.length()){
                    break;
                }
                c = file.charAt(idx2);
            }
            String number = file.substring(idx,idx2);
            String tail = file.substring(idx2);
            file_arr[i] = new File(head,number,i,tail);
        }
        Arrays.sort(file_arr);
        for(int i =0; i<files.length; i++){
            File f = file_arr[i];
            answer[i] = f.head+f.number+f.tail;
        }
    
        return answer;
    }
    
    public class File implements Comparable<File>{
        String head;
        String number;
        int idx;
        String tail;
        
        public File(String head, String number, int idx, String tail){
            this.head = head;
            this.number = number;
            this.idx = idx;
            this.tail = tail;
        }
        
        @Override
        public int compareTo(File o){
            int a = Integer.parseInt(this.number);
            int b = Integer.parseInt(o.number);
            String s_a = this.head.toLowerCase();
            String s_b = o.head.toLowerCase();
            if(s_a.compareTo(s_b)==0){
                if(a==b){
                    return this.idx - o.idx;
                }
                return a-b;
            }
            return s_a.compareTo(s_b);
        }
    }
}