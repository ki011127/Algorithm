#include<vector>
#include<queue>
using namespace std;

struct Point{
    int i;
    int j;
    int dist;
    Point(int i, int j, int dist){
        this->i = i;
        this->j = j;
        this->dist = dist;
    }
};

int solution(vector<vector<int> > maps)
{
    int answer = -1;
    vector<vector<bool>> visit_map(maps.size(), vector<bool>(maps[0].size(), true));
    int di[4] = {0,1,0,-1};
    int dj[4] = {1,0,-1,0};
    deque<Point> q;
    q.push_back(Point(0,0,1));
    visit_map[0][0] = false;
    
    while(!q.empty()){
        Point cur_point = q.front();
        q.pop_front();
        if(cur_point.i==maps.size()-1 && cur_point.j==maps[0].size()-1){
            return cur_point.dist;
        }
        for(int i = 0; i<4; i++){
            int ni = cur_point.i+di[i];
            int nj = cur_point.j+dj[i];
            if(ni>=0 && nj>=0 &&ni<maps.size() && nj<maps[0].size()){
                if(visit_map[ni][nj] && maps[ni][nj]==1){
                    q.push_back(Point(ni,nj,cur_point.dist+1));
                    visit_map[ni][nj] = false;
                }
            }
        }
    }
    
    return answer;
}