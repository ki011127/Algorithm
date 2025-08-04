import java.util.*;

class Solution {
    public long solution(String expression) {
        long answer = 0;
        char[] arr = {'+', '-', '*'};
        List<List<Character>> result = new ArrayList<>();
        boolean[] visited = new boolean[arr.length];
        backtrack(arr, visited, new ArrayList<>(), result);
        
        List<Long> numbers = new ArrayList<>();
        List<Character> expr = new ArrayList<>();
        int temp = 0;
        for(int i = 0; i<expression.length(); i++){
            char c = expression.charAt(i);
            if(c == '+' || c == '-' || c == '*'){
                numbers.add(Long.parseLong(expression.substring(temp,i)));
                expr.add(c);
                temp = i+1;
            }
        }
        numbers.add(Long.parseLong(expression.substring(temp)));
        
        for (List<Character> list : result) {
            List<Long> numbers_copy = new ArrayList<>();
            List<Character> expr_copy = new ArrayList<>();
            for (Long num : numbers) {
                numbers_copy.add(num);
            }
            for (Character ex : expr) {
                expr_copy.add(ex);
            }
            for(int i = 0; i<3; i++){
                for(int j = 0; j<expr_copy.size(); j++){
                    if(list.get(i)==expr_copy.get(j)){
                        if(list.get(i)=='+'){
                            numbers_copy.set(j,numbers_copy.get(j)+numbers_copy.get(j+1));
                            numbers_copy.remove(j+1);
                            expr_copy.remove(j);
                            j--;
                        }
                        else if(list.get(i)=='-'){
                            numbers_copy.set(j,numbers_copy.get(j)-numbers_copy.get(j+1));
                            numbers_copy.remove(j+1);
                            expr_copy.remove(j);
                            j--;
                        }
                        else{
                            numbers_copy.set(j,numbers_copy.get(j)*numbers_copy.get(j+1));
                            numbers_copy.remove(j+1);
                            expr_copy.remove(j);
                            j--;
                        }
                    }
                }
            }
            long num = Math.abs(numbers_copy.get(0));
            if(num>answer){
                answer = num;
            }
        }
        
        return answer;
    }
    public static void backtrack(char[] arr, boolean[] visited,
                                  List<Character> temp, List<List<Character>> result) {
        if (temp.size() == arr.length) {
            result.add(new ArrayList<>(temp));
            return;
        }
        for (int i = 0; i < arr.length; i++) {
            if (!visited[i]) {
                visited[i] = true;
                temp.add(arr[i]);
                backtrack(arr, visited, temp, result);
                temp.remove(temp.size() - 1);
                visited[i] = false;
            }
        }
    }
}