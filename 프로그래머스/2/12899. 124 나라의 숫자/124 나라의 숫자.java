class Solution {
    public String solution(int n) {
        StringBuilder sb = new StringBuilder();
        String[] digit = {"4", "1", "2"};

        while (n > 0) {
            sb.insert(0, digit[n % 3]);
            n = (n - 1) / 3;
        }
        return sb.toString();
    }
}