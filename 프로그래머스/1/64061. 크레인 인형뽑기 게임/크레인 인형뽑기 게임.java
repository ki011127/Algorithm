import java.util.*;

class Solution {
    public int solution(int[][] board, int[] moves) {
        int answer = 0;
        ArrayList<Integer> list = new ArrayList<>();
        for(int i = 0; i<moves.length; i++){
            int c = moves[i]-1;
            for(int j = 0; j<board.length; j++){
                if(board[j][c]!=0){
                    if(list.size()!=0 && list.get(list.size()-1)==board[j][c]){
                        list.remove(list.size()-1);
                        answer+=2;
                    }
                    else{
                        list.add(board[j][c]);
                    }
                    board[j][c]=0;
                    break;
                }
            }
        }
        return answer;
    }
}