#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int count_node(vector<vector<int>> &tree, int n){
    deque<int> dq;
    dq.push_back(1);
    vector<bool> visited(n+1, false);
    visited[1] = true;
    int count = 0;
    while(!dq.empty()){
        int cur = dq.front();
        dq.pop_front();
        count++;
        for(int next : tree[cur]){
            if(visited[next]){
                continue;
            }
            dq.push_back(next);
            visited[next]=true;
        }
    }
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 100;
    for(int i = 0; i<wires.size(); i++){
        vector<vector<int>> tree(n+1);
        for(int j = 0; j<wires.size(); j++){
            if(i==j){
                continue;
            }
            else{
                int v1 = wires[j][0];
                int v2 = wires[j][1];
                tree[v1].push_back(v2);
                tree[v2].push_back(v1);
            }
        }
        
        int count = count_node(tree, n);
        int count_2 = n-count;
        answer = min(answer, abs(count-count_2));
    }
    
    
    return answer;
}