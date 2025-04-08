#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;


struct Node {
    int to;
    int w;
    Node(int to, int w):to(to), w(w){}
    Node(){}
    bool operator<(const Node &node) const{
        return w > node.w;
    }
};
int visited[51] = {0, };
int *table;

vector<Node> edge[51];
void dij(){
    table[1] = 0;
    priority_queue<Node> q;
    q.push(Node(1,0));
    while(!q.empty()){
        Node current = q.top();
        q.pop();
        if(visited[current.to] == 1){
            continue;
        }
        visited[current.to] = 1;
        for(auto iter = edge[current.to].begin(); iter!=edge[current.to].end();iter++){
            
            if(table[iter->to] > current.w + iter->w){
                table[iter->to] = current.w + iter->w;
                q.push(Node(iter->to, table[iter->to]));
            }
        }
    }
}


int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    table = new int[N+1];
    fill(table, table + N + 1, INT_MAX);
    for(int i = 0; i<road.size(); i++){
        edge[road[i][0]].push_back(Node(road[i][1],road[i][2]));
        edge[road[i][1]].push_back(Node(road[i][0],road[i][2]));
    }

    dij();
    for(int i = 1; i<N+1; i++){
        if(table[i]<=K){
            answer++;
        }
    }
    return answer;
}