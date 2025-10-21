#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i = 0; i<scoville.size(); i++){
        pq.push(scoville[i]);
    }
    while(pq.size()>=2 &&pq.top()<K){
        int min_1 = pq.top();
        pq.pop();
        int min_2 = pq.top();
        pq.pop();
        pq.push(min_1+min_2*2);
        answer++;
    }
    if(pq.top()<K){
        return -1;
    }
    return answer;
}