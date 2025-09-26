class Solution {
    public int solution(String s) {
        int min_length = s.length();
        for(int len = 1; len<=s.length()/2; len++){
            int count = 1;
            StringBuilder temp_s = new StringBuilder(s);
            int temp_length = 0;
            String sub = s.substring(0,len);
            temp_s.delete(0, len);
            while(temp_s.length()>=len){
                if(temp_s.indexOf(sub)==0){
                    count++;
                    temp_s.delete(0,len);
                }
                else{
                    if(count==1){
                        temp_length+=len;
                    }
                    else{
                        temp_length+=(Integer.toString(count).length()+len);
                    }
                    count = 1;
                    sub = temp_s.substring(0,len);
                    temp_s.delete(0, len);
                }
            }
            if(count==1){
                temp_length+=(len+temp_s.length());
            }
            else{
                temp_length+=(Integer.toString(count).length()+len+temp_s.length());
            }
            min_length = Math.min(min_length,temp_length);
        }
        
        return min_length;
    }
}