import java.util.*;

class Solution {
    public static int gcd(int a, int b) {
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }
    
    public int solution(int[] arrayA, int[] arrayB) {
        int answer = 0;
        int gcdA = arrayA[0];
        for(int i = 1; i<arrayA.length; i++){
            gcdA = gcd(gcdA, arrayA[i]);
        }
        int gcdB = arrayB[0];
        for(int i = 1; i<arrayB.length; i++){
            gcdB = gcd(gcdB, arrayB[i]);
        }
        
        TreeSet<Integer> setA = new TreeSet<>((a, b) -> b - a);
        TreeSet<Integer> setB = new TreeSet<>((a, b) -> b - a);
        
        for(int i = 1; i*i<=gcdA; i++){
            if(gcdA%i==0){
                setA.add(i);
                if(gcdA/i!=i){
                    setA.add(gcdA/i);
                }
            }
        }
        
        for(int i = 1; i*i<=gcdB; i++){
            if(gcdB%i==0){
                setB.add(i);
                if(gcdB/i!=i){
                    setB.add(gcdB/i);
                }
            }
        }
        
        for(Integer a : setA){
            int flag = 0;
            for(int i = 0; i<arrayB.length; i++){
                if(arrayB[i]%a==0){
                    flag = 1;
                    break;
                }
            }
            if (flag==0){
                answer = a;
                break;
            }
        }
        for(Integer b: setB){
            int flag = 0;
            for(int i = 0; i<arrayA.length; i++){
                if(arrayA[i]%b==0){
                    flag = 1;
                    break;
                }
            }
            if (flag==0 && answer<b){
                answer = b;
                break;
            }
        }
        
        return answer;
    }
}