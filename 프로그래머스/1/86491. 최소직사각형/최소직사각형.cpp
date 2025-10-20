#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int w = 0;
    int h = 0;
    for(int i = 0; i<sizes.size(); i++){
        w = max({w,sizes[i][0], sizes[i][1]});
    }
    for(int i = 0; i<sizes.size(); i++){
        int n = min(sizes[i][0], sizes[i][1]);
        h = max(h,n);
    }
    answer=w*h;
    return answer;
}