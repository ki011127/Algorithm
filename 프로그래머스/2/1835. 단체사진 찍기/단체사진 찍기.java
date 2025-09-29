class Solution {
    char[] friends = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    boolean[] visited = new boolean[8];
    int answer = 0;
    public int solution(int n, String[] data) {
        dfs("", data);
        return answer;
    }
    
    public void dfs(String arrange, String[] data){
        if(arrange.length()==8){
            if(is_valid(arrange, data)){
                answer++;
            }
            return;
        }
        
        for(int i = 0; i<8; i++){
            if(!visited[i]){
                visited[i] = true;
                dfs(arrange+friends[i], data);
                visited[i] = false;
            }
        }
    }
    public boolean is_valid(String arrange,String[] data){
        for(String s : data){
            char a = s.charAt(0);
            char b = s.charAt(2);
            char op = s.charAt(3);
            int num = s.charAt(4)-'0';
            int dist = Math.abs(arrange.indexOf(a)-arrange.indexOf(b)) -1;
            
            if(op=='=' && num!=dist){
                return false;
            }
            if(op=='<' && num<=dist){
                return false;
            }
            if(op=='>' && num>=dist){
                return false;
            }
        }
        return true;
    }
}