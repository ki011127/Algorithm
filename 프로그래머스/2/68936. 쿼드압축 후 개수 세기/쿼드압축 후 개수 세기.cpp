#include <string>
#include <vector>
#include <iostream>
using namespace std;

int count_zero = 0;
int count_one = 0;
void solve(const vector<vector<int>>& arr, int len, int x, int y);

vector<int> solution(vector<vector<int>> arr) {
    int len = arr.size();
    solve(arr, len, 0, 0);
    
    vector<int> answer;
    answer.push_back(count_zero);
    answer.push_back(count_one);
    
    return answer;
}

void solve(const vector<vector<int>>& arr, int len, int x, int y){
    int val = arr[x][y];
    int dx[4] = {x, x, x+len/2, x+len/2};
    int dy[4] = {y, y+len/2, y, y+len/2};
    
    for(int i = x; i<x+len; i++){
        for(int j = y; j<y+len; j++){
            if(arr[i][j]!=val){
                solve(arr, len/2, dx[0], dy[0]);
                solve(arr, len/2, dx[1], dy[1]);
                solve(arr, len/2, dx[2], dy[2]);
                solve(arr, len/2, dx[3], dy[3]);
                
                return;
            }
        }
    }
    if(val==0){
        count_zero++;
    }
    else{
        count_one++;
    }
    
    return;
}