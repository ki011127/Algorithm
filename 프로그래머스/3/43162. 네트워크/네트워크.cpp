#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;
unordered_set<int> s;

void check(int computer, const vector<vector<int>>& computers, int n){
    for(int j=0; j<n; j++){
        if(computer!=j && computers[computer][j]==1 && s.count(j)==0){
            s.insert(j);
            check(j, computers, n);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i = 0; i<n; i++){
        if(s.count(i)==0){
            s.insert(i);
            answer++;
            check(i, computers, n);
        }
    }
    
    return answer;
}