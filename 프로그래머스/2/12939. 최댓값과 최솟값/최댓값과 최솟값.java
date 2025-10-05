import java.util.*;

class Solution {
    public String solution(String s) {
        String[] nums = s.split(" ");
        int[] numbers = new int[nums.length];
        for(int i = 0; i<nums.length; i++){
            numbers[i] = Integer.parseInt(nums[i]);
        }
        
        Arrays.sort(numbers);
        
        StringBuilder sb = new StringBuilder();
        
        sb.append(numbers[0]);
        sb.append(" ");
        sb.append(numbers[numbers.length-1]);
        
        return sb.toString();
    }
}