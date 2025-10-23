#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int idx = 0; idx<commands.size(); idx++){
        int i = commands[idx][0];
        int j = commands[idx][1];
        int k = commands[idx][2];
        vector<int> array_copy(array.begin()+i-1, array.begin()+j);
        sort(array_copy.begin(), array_copy.end());
        answer.push_back(array_copy[k-1]);
        
    }
    return answer;
}