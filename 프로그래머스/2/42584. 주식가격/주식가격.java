import java.util.*;

class Solution {
    public int[] solution(int[] prices) {
        int[] answer = new int[prices.length];
        Deque<Node> deque = new ArrayDeque<>();
        deque.addLast(new Node(prices[0],0));
        for(int i = 1; i<prices.length; i++){
            
            while(deque.peekLast().price>prices[i]){
                answer[deque.peekLast().idx] = i-deque.peekLast().idx;
                deque.pollLast();
                if(deque.size()==0){
                    break;
                }
            }
            deque.addLast(new Node(prices[i],i));
        }

        while(deque.size()!=0){
            Node node = deque.pollLast();
            answer[node.idx] = prices.length-1-node.idx;
        }
        
        return answer;
    }
    class Node{
        int price;
        int idx;
        public Node(int price, int idx){
            this.price = price;
            this.idx = idx;
        }
    }
}