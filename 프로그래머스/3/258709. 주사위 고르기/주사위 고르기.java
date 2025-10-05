import java.util.*;

class Solution {
    public int[] solution(int[][] dice) {
        
        ArrayList<Integer> best = new ArrayList<>();
        int n = dice.length;
        int h = n/2;
        int maxCount = 0;
        for(int bit = 0; bit<(1<<n); bit++){
            if(Integer.bitCount(bit)==h){
                ArrayList<Integer> A = new ArrayList<>();
                ArrayList<Integer> B = new ArrayList<>();
                
                for(int i = 0; i<n; i++){
                    if((bit&(1<<i))!=0){
                        A.add(i);
                    }
                    else{
                        B.add(i);
                    }
                }
                ArrayList<Integer> sumA = new ArrayList<>();
                ArrayList<Integer> sumB = new ArrayList<>();
                calculate(A, dice, sumA, 0,0);
                calculate(B, dice, sumB, 0,0);
                Collections.sort(sumA);
                Collections.sort(sumB);
                
                
                int count=0;
                for(int i = 0; i<sumA.size(); i++){
                    int a = sumA.get(i);
                    count += b_search(sumB, a);
                }
                if(maxCount<count){
                    maxCount = count;
                    best = new ArrayList<>(A);
                }
            }
        }
        int[] answer = new int[best.size()];
        for(int i = 0; i<best.size(); i++){
            answer[i] = best.get(i)+1;
        }
        return answer;
    }
    
    public int b_search(ArrayList<Integer> list, int target){
        int left = 0;
        int right = list.size();
        while(left<right){
            int mid = (left+right)/2;
            if(list.get(mid)<target){
                left = mid+1;
            }
            else{
                right = mid;
            }
        }
        return left;
    }
    
    public void calculate(ArrayList<Integer> list, int[][] dice, ArrayList<Integer> result, int depth, int sum){
        if(depth==list.size()){
            result.add(sum);
            return;
        }
        
        for(int i =0; i<6; i++){
            calculate(list, dice, result, depth+1, sum+dice[list.get(depth)][i]);
        }
    }
}