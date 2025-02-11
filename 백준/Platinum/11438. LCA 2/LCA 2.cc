#include <iostream>
#include <vector>
#include <deque>

using namespace std;
int constant = 17;
int N;
vector<int> v[100001];
int *depth;
int **parent;
int *visited;

void bfs(){
    deque<int> dq;
    dq.push_back(1);
    parent[0][1] = 0;
    depth[1] = 0;
    visited[1] = 1;

    while(!dq.empty()){
        int cur_node = dq.front();
        dq.pop_front();
        for(auto iter = v[cur_node].begin(); iter!=v[cur_node].end(); iter++){
            if(visited[*iter]!=1){
                depth[*iter] = depth[cur_node]+1;
                parent[0][*iter] = cur_node;
                visited[*iter] = 1;
                dq.push_back(*iter);
            } 
        }
    }
}

void make_ancestor_arr(){
    for(int k = 1; k<=constant; k++){
        for(int v = 1; v<=N; v++){
            parent[k][v] = parent[k-1][parent[k-1][v]];
        }
    }
}

int LCA(int a, int b){
    if(depth[a]>depth[b]){
        int temp = b;
        b = a;
        a = temp;
    }
    for(int i = constant; i>=0; i--){
        if(depth[b]-depth[a]>=(1<<i)){
            b= parent[i][b];
        }
    }
    if(b==a){
        return a;
    }
    for(int k = constant; k>=0; k--){
        if(parent[k][a]!=parent[k][b]){
            a = parent[k][a];
            b = parent[k][b];
        }
    }
    return parent[0][a];
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    depth = new int[N+1];
    visited = new int[N+1];
    parent = new int*[constant+1];
    for(int i = 0; i<=constant; i++){
        parent[i] = new int[N+1];
    }

    for(int i = 0; i<N-1; i++){
        int from, to;
        cin >> from >> to;
        v[from].push_back(to);
        v[to].push_back(from);
    }
    bfs();
    make_ancestor_arr();
    int Q;
    cin >> Q;
    for(int i = 0; i<Q; i++){
        int a,b;
        cin >> a >> b;
        
        cout << LCA(a,b) << "\n";
    }

    return 0;
}