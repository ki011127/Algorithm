#include <string>
#include <vector>

using namespace std;
int answer = 0;

void solve(const vector<int>& numbers, int num, int target, int idx){
    if(idx==numbers.size()-1){
        if(num+numbers[idx]==target || num-numbers[idx]==target){
            answer++;
        }
        return;
    }
    
    solve(numbers, num+numbers[idx], target, idx+1);
    solve(numbers, num-numbers[idx], target, idx+1);
}

int solution(vector<int> numbers, int target) {
    solve(numbers, 0, target, 0);
    return answer;
}