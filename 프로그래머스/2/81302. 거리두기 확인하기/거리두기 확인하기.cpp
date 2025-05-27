#include <string>
#include <vector>
#include <iostream>
using namespace std;

int find(vector<string> map, int cx, int cy, int dist, int fx, int fy){
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    for(int i = 0; i<4; i++){
        
        int nx = cx+dx[i];
        int ny = cy+dy[i];
        
        if(nx<5 && ny < 5 && nx >= 0 && ny >= 0 && (fx!=nx || fy!=ny)){
            if(dist<2){
                if(map[ny][nx]=='P'){
                    return 1;
                }
                else if(map[ny][nx]=='X'){
                    continue;
                }
                else{
                    if(find(map, nx, ny, dist+1, fx, fy)){
                        return 1;
                    }
                }
            }
            else{
                if(map[ny][nx]=='P'){
                    return 1;
                }
            }
        }
    }
    return 0;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    int flag = 0;
    for(int k = 0; k<places.size(); k++){
        for(int y = 0; y<places[k].size(); y++){
            for(int x = 0; x<5; x++){
                if(places[k][y][x]=='P'){
                    flag = find(places[k], x, y, 1, x, y);
                    if(flag){
                        break;
                    }
                }
            }
            if(flag){
                answer.push_back(0);
                break;
            }
        }
        if(flag==0){
            answer.push_back(1);
        }
        flag = 0;
    }
    
    return answer;
}