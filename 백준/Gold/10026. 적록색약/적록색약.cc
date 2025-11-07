#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void dfs(int x, int y, char c, vector<vector<bool>> &visited, vector<string> &map){
    visited[y][x] = true;

    for(int i = 0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(nx>=0 && ny>=0 && nx<N && ny<N){
            if(!visited[ny][nx] && map[ny][nx]==c){
                dfs(nx, ny, c, visited, map);
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    vector<string> map(N);

    for (int i = 0; i < N; i++) {
        string row;
        cin >> map[i];
    }

    vector<vector<bool>> visited(N, vector<bool>(N, false));
    int count = 0;
    for(int i =0; i<N; i++){
        for(int j  =0; j<N; j++){
            if(!visited[i][j]){
                count++;
                dfs(j,i,map[i][j],visited, map);
            }
        }
    }

    for(int i =0; i<N; i++){
        for(int j  =0; j<N; j++){
            if(map[i][j]=='G'){
                map[i][j] = 'R';
            }
            visited[i][j] = false;
        }
    }
    int count2 = 0;
    for(int i =0; i<N; i++){
        for(int j  =0; j<N; j++){
            if(!visited[i][j]){
                count2++;
                dfs(j,i,map[i][j],visited, map);
            }
        }
    }


    cout << count << " " << count2;
    return 0;

}