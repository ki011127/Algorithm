import java.util.*;

class Solution {
    public int solution(int[] people, int limit) {
        int answer = 0;

        Arrays.sort(people);
        
        
        int l = 0;
        int r = people.length-1;
        
        while(l<=r){
            answer++;
            int num = limit - people[r];
            if(num>=people[l]){
                l++;
            }
            r--;
        }
        
        return answer;
    }
}