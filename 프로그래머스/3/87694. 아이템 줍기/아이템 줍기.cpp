#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct Point{
    int x;
    int y;
    int dist;
};

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    vector<vector<int>> map(101, vector<int>(101, -1));
    for(int idx = 0; idx<rectangle.size(); idx++){
        int x1 = rectangle[idx][0]*2;
        int y1 = rectangle[idx][1]*2;
        int x2 = rectangle[idx][2]*2;
        int y2 = rectangle[idx][3]*2;
        for(int i = y1; i<=y2; i++){
            for(int j = x1; j<=x2; j++){
                if(y1<i && x1<j && i<y2 && j<x2){
                    map[i][j] = 0;
                }
                else if(map[i][j]==-1){
                    map[i][j] = 1;
                }
            }
        }
    }
    vector<vector<bool>> visited(101, vector<bool>(101,false));
    deque<Point> dq;
    
    dq.push_back({characterX*2, characterY*2, 0});
    visited[characterY*2][characterX*2] = true;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    while(!dq.empty()){
        Point p = dq.front();
        dq.pop_front();
        if(p.x==itemX*2 && p.y==itemY*2){
            return p.dist/2;
        }
        for(int i = 0; i<4; i++){
            int nx = p.x+dx[i];
            int ny = p.y+dy[i];
            if(nx>=0 && ny>=0 && nx<=100 && ny<=100){
                if(map[ny][nx]==1 && !visited[ny][nx]){
                    dq.push_back({nx, ny, p.dist+1});
                    visited[ny][nx]=true;
                }
            }
            
        }
        
    }
    
    
    return answer;
}