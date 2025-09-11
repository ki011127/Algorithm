class Solution {
    public String[] solution(int n, int[] arr1, int[] arr2) {
        String[] m = new String[n];
        
        for(int i = 0; i<n; i++){
            String arr1_row = Integer.toString(arr1[i],2);
            String arr2_row = Integer.toString(arr2[i],2);
            arr1_row = String.format("%"+n+"s", arr1_row).replaceAll(" ", "0");
            arr2_row = String.format("%"+n+"s", arr2_row).replaceAll(" ", "0");
            StringBuilder sb = new StringBuilder();
            for(int j = 0; j<n; j++){
                
                if(arr1_row.charAt(j)=='1' || arr2_row.charAt(j)=='1'){
                    sb.append("#");
                }
                else{
                    sb.append(" ");
                }
                
            }
            m[i] = sb.toString();
        }
        
        return m;
    }
}