import java.util.*;

class Solution {
    public int solution(int cacheSize, String[] cities) {
        if (cacheSize==0){
            return cities.length*5;
        }
        LinkedList<String> cache = new LinkedList<>();
        int answer = 0;
        for(String city : cities){
            city = city.toLowerCase();
            if(cache.remove(city)){
                answer++;
                cache.addLast(city);
            }
            else{
                if(cache.size()==cacheSize){
                    cache.removeFirst();
                }
                answer+=5;
                cache.addLast(city);
            }
        }
        return answer;
    }
}