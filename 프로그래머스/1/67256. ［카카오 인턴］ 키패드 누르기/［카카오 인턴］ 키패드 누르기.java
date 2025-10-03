class Solution {
    public String solution(int[] numbers, String hand) {
        StringBuilder sb = new StringBuilder();
        int l_row = 3;
        int l_col = 0;
        int r_row = 3;
        int r_col = 2;
        
        for(int i = 0; i<numbers.length; i++){
            int num = numbers[i]-1;
            int row = num/3;
            int col = num%3;
            if(num==-1){
                row = 3;
                col = 1;
            }
            if(col==0){
                sb.append("L");
                l_col = col;
                l_row = row;
            }
            else if(col==2){
                sb.append("R");
                r_col = col;
                r_row = row;
            }
            else{
                int l_dist = Math.abs(l_col-col) + Math.abs(l_row-row);
                int r_dist = Math.abs(r_col-col) + Math.abs(r_row-row);
                if(l_dist == r_dist){
                    if(hand.equals("left")){
                        sb.append("L");
                        l_col = col;
                        l_row = row;
                    }
                    else{
                        sb.append("R");
                        r_col = col;
                        r_row = row;
                    }
                }
                else if(l_dist>r_dist){
                    sb.append("R");
                    r_col = col;
                    r_row = row;
                }
                else{
                    sb.append("L");
                    l_col = col;
                    l_row = row;
                }
            }
        }
        
        
        return sb.toString();
    }
}