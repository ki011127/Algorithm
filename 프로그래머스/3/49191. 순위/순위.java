import java.util.*;

class Solution {
    public int solution(int n, int[][] results) {
        List<List<Integer>> graph = new ArrayList<>();
        List<List<Integer>> reverseGraph = new ArrayList<>();
        
        for (int i = 0; i <= n; i++) {
            graph.add(new ArrayList<>());
            reverseGraph.add(new ArrayList<>());
        }

        for (int[] result : results) {
            int win = result[0];
            int lose = result[1];
            graph.get(win).add(lose);        
            reverseGraph.get(lose).add(win); 
        }

        int answer = 0;
        for (int i = 1; i <= n; i++) {
            int winCount = bfs(i, graph, n);
            int loseCount = bfs(i, reverseGraph, n);

            if (winCount + loseCount == n - 1) {
                answer++;
            }
        }

        return answer;
    }
    public int bfs(int start, List<List<Integer>> graph, int n) {
        boolean[] visited = new boolean[n + 1];
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(start);
        visited[start] = true;

        int count = 0;

        while (!queue.isEmpty()) {
            int current = queue.poll();
            for (int next : graph.get(current)) {
                if (!visited[next]) {
                    visited[next] = true;
                    queue.offer(next);
                    count++;
                }
            }
        }
        return count;
    }
    
}