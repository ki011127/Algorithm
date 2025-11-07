#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Node{
    int x;
    int y;
    int count;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N;
    cin >> M >> N;  // M: 가로, N: 세로

    vector<vector<int>> box(N, vector<int>(M));
    deque<Node> q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> box[i][j];
            if(box[i][j]==1){
                q.push_back({j,i,0});
            }
        }
    }

    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    int answer = 0;
    while(!q.empty()){
        Node node = q.front();
        q.pop_front();
        int cx = node.x;
        int cy = node.y;
        answer= max(answer, node.count);
        for(int i =0; i<4; i++){
            int nx = cx+dx[i];
            int ny = cy+dy[i];
            if(nx>=0 && ny>=0 && nx<M && ny<N){
                if(box[ny][nx]==0){
                    
                    q.push_back({nx,ny,node.count+1});
                    box[ny][nx]=1;
                }
            }
        }

    }


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if(box[i][j]==0){
                cout << -1;
                return 0;
            }
        }
    }
    cout << answer;
    return 0;
}
