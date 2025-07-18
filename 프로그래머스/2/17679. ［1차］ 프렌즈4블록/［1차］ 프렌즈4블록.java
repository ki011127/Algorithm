class Solution {
    public int same_block(int[][] int_board, String[] board, int m, int n){
        int count = 0;
        for(int i = 0; i<m-1; i++){
            for(int j = 0; j<n-1; j++){
                char c = board[i].charAt(j);
                char r = board[i].charAt(j+1);
                char d = board[i+1].charAt(j);
                char dia = board[i+1].charAt(j+1);
                if(c==r && c==d && c==dia && c!='X'){
                    for(int k = 0; k<2; k++){
                        for(int l = 0; l<2; l++){
                            if(int_board[i+k][j+l]==0){
                                count++;
                                int_board[i+k][j+l] = 1;
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
    
    public void next_stage(int[][] int_board, String[] board, int m, int n){
        for(int j = 0; j<n; j++){
            for(int i = m-1; i>=0; i--){
                if(int_board[i][j]==1){
                    for(int k = i-1; k>=0; k--){
                        if(int_board[k][j]==0){
                            StringBuilder sb = new StringBuilder(board[i]);
                            sb.setCharAt(j, board[k].charAt(j));
                            board[i] = sb.toString();
                            int_board[i][j] = 0;
                            int_board[k][j] = 1;
                            break;

                        }
                    }
                    if(int_board[i][j]==1){
                        StringBuilder sb = new StringBuilder(board[i]);
                        sb.setCharAt(j, 'X');
                        board[i] = sb.toString();
                    }
                }
            }
        }
    }
    
    public int solution(int m, int n, String[] board) {
        int answer = 0;
        int count = 0;
        
        while(true){
            int[][] int_board = new int[m][n];
            count = same_block(int_board, board, m, n);
            next_stage(int_board, board, m, n);
            if(count==0){
                break;
            }
            else{
                answer+=count;
            }
        }
        return answer;
    }
}