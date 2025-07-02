class Solution {
    public String int_to_string(int num){
        if(num >= 10) return String.valueOf((char)('A' + (num - 10)));
        return String.valueOf(num);
    }

    public String convert(int num, int base) {
        if (num == 0) return "0";
        StringBuilder sb = new StringBuilder();
        while(num > 0){
            sb.insert(0, int_to_string(num % base));
            num /= base;
        }
        return sb.toString();
    }

    public String solution(int n, int t, int m, int p) {
        StringBuilder all = new StringBuilder();
        int num = 0;

        while(all.length() < t * m){
            all.append(convert(num, n));
            num++;
        }

        StringBuilder answer = new StringBuilder();
        for(int i = 0; i < t; i++){
            answer.append(all.charAt(i * m + (p - 1)));
        }

        return answer.toString();
    }
}