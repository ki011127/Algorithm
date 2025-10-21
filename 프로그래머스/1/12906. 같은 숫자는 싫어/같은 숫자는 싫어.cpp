#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int idx = 0;
    answer.push_back(arr[0]);
    for(int i = 1; i<arr.size(); i++){
        if(arr[i]==answer[idx]){
            continue;
        }
        answer.push_back(arr[i]);
        idx++;
    }

    return answer;
}