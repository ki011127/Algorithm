class Solution {
    public static boolean isPrime(long n) {
        if (n <= 1) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;

        for (long i = 3; i * i <= n; i += 2) {
            if (n % i == 0) return false;
        }
        return true;
    }
    
    
    public int solution(int n, int k) {
        int answer = 0;
        String trans = Integer.toString(n, k);
        int start = 0;
        for(int i = 0; i<trans.length(); i++){
            if(trans.charAt(i)=='0' && start != i){
                String sub = trans.substring(start, i);
                if(isPrime(Long.parseLong(sub))){
                    answer++;
                }
                start = i+1;
            }
        }
        if (start < trans.length()) {
            String sub = trans.substring(start);
            if (isPrime(Long.parseLong(sub))) {
                answer++;
            }
        }
        return answer;
    }
}