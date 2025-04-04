#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<vector<int>> square;
    vector<int> answer;
    int num = 1;
    for(int i = 0; i<rows; i++){
        vector<int> v;
        for(int j = 0; j<columns; j++){
            v.push_back(num++);
        }
        square.push_back(v);
    }
    for(int i = 0; i < queries.size(); i++){
        int x1 = queries[i][0]-1;
        int y1 = queries[i][1]-1;
        int x2 = queries[i][2]-1;
        int y2 = queries[i][3]-1;
        int cx = x1;
        int cy = y1;
        
        int next_val = square[cx][cy];
        int min_val = next_val;
        int temp;
        for(;cy<y2; cy++){
            temp = square[cx][cy+1];
            square[cx][cy+1] = next_val;
            next_val = temp;
            if(next_val<min_val){
                min_val = next_val;
            }
        }
        for(;cx<x2; cx++){
            temp = square[cx+1][cy];
            square[cx+1][cy] = next_val;
            next_val = temp;
            if(next_val<min_val){
                min_val = next_val;
            }
        }
        for(;cy>y1; cy--){
            temp = square[cx][cy-1];
            square[cx][cy-1] = next_val;
            next_val = temp;
            if(next_val<min_val){
                min_val = next_val;
            }
        }
        for(;cx>x1; cx--){
            temp = square[cx-1][cy];
            square[cx-1][cy] = next_val;
            next_val = temp;
            if(next_val<min_val){
                min_val = next_val;
            }
        }
        // for(int i = 0; i<rows; i++){
        //     for(int j = 0; j<columns; j++){
        //         cout << square[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";
        answer.push_back(min_val);
    }
    
    
    return answer;
}