#include <string>
#include <vector>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    for (char c : number) {
        // 현재 숫자가 스택의 마지막 숫자보다 크면 pop
        while (!answer.empty() && k > 0 && answer.back() < c) {
            answer.pop_back();
            k--;
        }
        answer.push_back(c);
    }
    
    // 아직 제거 횟수가 남아있으면 뒤에서 제거
    while (k > 0) {
        answer.pop_back();
        k--;
    }
    
    return answer;
}