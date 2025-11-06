#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node{
    int x;
    int y;
    int dist;
};

int main(void){
    int N,M;
    cin >> N >> M;
    vector<vector<int>> map(N, vector<int>(M,0));

    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;  // "101111" 이런 형태의 문자열 입력 받음
        for (int j = 0; j < M; j++) {
            map[i][j] = row[j] - '0';  // 문자 '1' → 숫자 1로 변환
        }
    }

    vector<vector<bool>> visited(N, vector<bool>(M,false));
    deque<Node> q;

    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    q.push_back({0,0,1});
    visited[0][0] = true;
    int answer=0;
    while(!q.empty()){

        Node cur_node = q.front();
        int cx = cur_node.x;
        int cy = cur_node.y;
        if(cx==M-1 && cy==N-1){
            answer= cur_node.dist;
            break;
        }
        q.pop_front();
        for(int i = 0; i<4; i++){
            int nx = cx+dx[i];
            int ny = cy+dy[i];
            if(nx>=0 && ny>=0 && nx<M && ny<N){
                if(!visited[ny][nx] && map[ny][nx]==1){
                    q.push_back({nx,ny,cur_node.dist+1});
                    visited[ny][nx]=true;
                }
            }
        }

    }
    cout<< answer;

    return 0;
}