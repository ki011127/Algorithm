class Solution {
    public int solution(String dartResult) {
        int answer = 0;
        int idx = 0;
        
        int[] score = new int[3];
        for(int i = 0; i<3; i++){
            int start_idx = idx;
            while(Character.isDigit(dartResult.charAt(idx))){
                idx++;
            }

            int num = Integer.parseInt(dartResult.substring(start_idx,idx));
            char bonus = dartResult.charAt(idx++);
            char option = '%';
            if(idx!=dartResult.length() && !Character.isDigit(dartResult.charAt(idx))){
                option = dartResult.charAt(idx++);
            }
            if(bonus=='S'){
                score[i] = num;
            }
            else if(bonus=='D'){
                score[i] = num*num;
            }
            else{
                score[i] = num*num*num;
            }
            
            if(option=='*'){
                score[i]*=2;
                if(i!=0){
                    score[i-1]*=2;
                }
            }
            else if(option=='#'){
                score[i]*=-1;
            }
            
            
        }
        
        return score[0]+score[1]+score[2];
    }
}