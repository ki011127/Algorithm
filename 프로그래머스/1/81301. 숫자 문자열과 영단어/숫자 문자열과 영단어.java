class Solution {
    public int solution(String s) {
        String[] str_nums = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        
        for(int i = 0; i<str_nums.length; i++){
            s = s.replaceAll(str_nums[i], Integer.toString(i));
        }
        
        return Integer.parseInt(s);
    }
}