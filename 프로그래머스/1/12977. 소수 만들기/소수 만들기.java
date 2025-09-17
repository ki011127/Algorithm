class Solution {
    public int solution(int[] nums) {
        int answer = 0;
        int[] is_prime = new int[3001];
        
        for(int i = 2; i*i<is_prime.length; i++){
            if(is_prime[i]==0){
                for(int j = i*i; j<is_prime.length; j+=i){
                    is_prime[j] = 1;
                }
            }
        }
        
        for(int i = 0; i<nums.length; i++){
            for(int j =i+1; j<nums.length; j++){
                for(int k = j+1; k<nums.length; k++){
                    if(is_prime[nums[i]+nums[j]+nums[k]]==0){
                        answer++;
                    }
                }
            }
        }
        

        return answer;
    }
}