#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> operations) {
    priority_queue<int> max_q;
    priority_queue<int, vector<int>, greater<int>> min_q;
    unordered_map<int, int> count; 

    for (auto &op : operations) {
        if (op[0] == 'I') {
            int num = stoi(op.substr(2));
            max_q.push(num);
            min_q.push(num);
            count[num]++;
        } else if (op == "D 1") { 
            while (!max_q.empty() && count[max_q.top()] == 0)
                max_q.pop();
            if (!max_q.empty()) {
                count[max_q.top()]--;
                max_q.pop();
            }
        } else if (op == "D -1") { 
            while (!min_q.empty() && count[min_q.top()] == 0)
                min_q.pop();
            if (!min_q.empty()) {
                count[min_q.top()]--;
                min_q.pop();
            }
        }
    }

    while (!max_q.empty() && count[max_q.top()] == 0) max_q.pop();
    while (!min_q.empty() && count[min_q.top()] == 0) min_q.pop();

    vector<int> answer(2, 0);
    if (!max_q.empty() && !min_q.empty()) {
        answer[0] = max_q.top();
        answer[1] = min_q.top();
    }
    return answer;
}