#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void norm(vector<pair<int,int>> &ret){
    int min_x = 50;
    int min_y = 50;
    for(auto &p : ret){
        min_x = min(min_x, p.first);
        min_y = min(min_y, p.second);
    }
    
    for(auto &p : ret){
        p.first -= min_x;
        p.second -= min_y;
    }
    sort(ret.begin(), ret.end());
}

vector<pair<int,int>> bfs(vector<vector<int>>& map, vector<vector<bool>> &visited, int x, int y, int target){
    vector<pair<int,int>> ret;
    deque<pair<int,int>> q;
    q.push_back({x,y});
    visited[y][x] = true;
    ret.push_back({x, y});
    while(!q.empty()){
        pair<int,int> cur = q.front();
        q.pop_front();
        for(int i = 0; i<4; i++){
            int nx = cur.first+dx[i];
            int ny = cur.second+dy[i];
            
            if(nx>=0 && ny>=0 && nx<map.size() && ny<map.size()){
                if(!visited[ny][nx] && map[ny][nx]==target){
                    q.push_back({nx,ny});
                    visited[ny][nx] = true;
                    ret.push_back({nx, ny});
                }
            }
        }
    }
    norm(ret);
    return ret;
}

vector<pair<int,int>> rotate(vector<pair<int,int>> s){
    for(auto &p : s){
        int x = p.first;
        int y = p.second;
        p.first = -y;
        p.second = x;
    }
    norm(s);
    return s;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    int n = game_board.size();
    vector<vector<pair<int,int>>> empty;
    vector<vector<pair<int,int>>> piece;
    
    vector<vector<bool>> visited_board(n, vector<bool>(n, false));
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(game_board[i][j]==0 && !visited_board[i][j]){
                empty.push_back(bfs(game_board, visited_board, j, i,0));
            }
        }
    }
    vector<vector<bool>> visited_table(n, vector<bool>(n, false));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(table[i][j]==1 && !visited_table[i][j]){
                piece.push_back(bfs(table, visited_table, j, i,1));
            }
        }
    }
    vector<bool> visited(piece.size(), false);
    for(auto &e : empty){
        int flag = 0;
        for(int i = 0; i<piece.size(); i++){
            if(visited[i]){
                continue;
            }
            auto cur = piece[i];
            for(int j = 0; j<4; j++){
                if(e==cur){
                    answer+=e.size();
                    visited[i]= true;
                    flag = 1;
                    break;
                }
                cur = rotate(cur);
            }
            if(flag==1){
                break;
            }
        }
    }
    
    return answer;
}