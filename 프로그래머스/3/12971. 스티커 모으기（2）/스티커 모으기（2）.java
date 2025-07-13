class Solution {
    public int solution(int sticker[]) {

        if(sticker.length==1){
            return sticker[0];
        }
        if(sticker.length==2){
            return Math.max(sticker[0], sticker[1]);
        }

        int[] dp_a = new int[sticker.length];
        dp_a[0] = sticker[0];
        dp_a[1] = sticker[0];
        for(int i = 2; i<sticker.length-1; i++){
            dp_a[i] = Math.max(dp_a[i-2]+sticker[i], dp_a[i-1]);
        }
        
        int[] dp_b = new int[sticker.length];
        dp_b[1] = sticker[1];
        dp_b[2] = Math.max(sticker[1],sticker[2]);
        for(int i = 3; i<sticker.length; i++){
            dp_b[i] = Math.max(dp_b[i-2]+sticker[i], dp_b[i-1]);
        }
        return Math.max(dp_a[sticker.length-2], dp_b[sticker.length-1]);
    }
}