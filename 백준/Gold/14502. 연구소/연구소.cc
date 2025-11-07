#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int answer = 0;
int M, N;
void bfs(vector<vector<int>> &map){
    deque<pair<int,int>> q;
    for(int i =0; i<N; i++){
        for(int j = 0; j<M; j++){
            if(map[i][j]==2){
                q.push_back({j,i});
            }
        }
    }

    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop_front();

        for(int i =0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0 && ny>=0 && nx<M && ny<N){
                if(map[ny][nx]==0){
                    q.push_back({nx,ny});
                    map[ny][nx] = 2;
                }
            }

        }
    }

    int area = 0;
    for(int i = 0; i<N; i++){
        for(int j =0; j<M; j++){
            if(map[i][j]==0){
                area++;
            }
        }
    }
    answer = max(answer, area);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> N >> M;  // M: 가로, N: 세로

    vector<vector<int>> map(N, vector<int>(M));
    vector<pair<int,int>> candidate;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if(map[i][j]==0){
                candidate.push_back({j,i});
            }
        }
    }

    for(int i =0; i<candidate.size(); i++){
        for(int j =i+1; j<candidate.size(); j++){
            for(int k = j+1; k<candidate.size(); k++){
                vector<vector<int>> tmp(N, vector<int>(M));
                for (int a = 0; a < N; a++)
                    for (int b = 0; b < M; b++)
                        tmp[a][b] = map[a][b];

                auto [wx1,wy1] = candidate[i];
                auto [wx2,wy2] = candidate[j];
                auto [wx3,wy3] = candidate[k];

                tmp[wy1][wx1] = 1;
                tmp[wy2][wx2] = 1;
                tmp[wy3][wx3] = 1;
                bfs(tmp);
            }
        }
    }

    cout << answer;

    return 0;
}