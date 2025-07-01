import java.util.*;
class Solution {
    public int solution(String[][] book_time) {
        int answer = 0;
        int[][] transform_book_time = new int[book_time.length][2];
        for(int i = 0; i<book_time.length; i++){
            int start_h = Integer.parseInt(book_time[i][0].split(":")[0]);
            int start_m = Integer.parseInt(book_time[i][0].split(":")[1]);
            int end_h = Integer.parseInt(book_time[i][1].split(":")[0]);
            int end_m = Integer.parseInt(book_time[i][1].split(":")[1]);
            transform_book_time[i][0] = start_h*60+start_m;
            transform_book_time[i][1] = end_h*60+end_m+10;
        }
        Arrays.sort(transform_book_time, (a, b) -> a[0] - b[0]);
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
        for(int i = 0; i<book_time.length; i++){
            int start = transform_book_time[i][0];
            int end = transform_book_time[i][1];
            if(!pq.isEmpty() && pq.peek()<=start){
                pq.poll();
            }
            pq.add(end);
        }
        return pq.size();
    }
}