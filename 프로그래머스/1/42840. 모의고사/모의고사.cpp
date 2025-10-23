#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    deque<int> d1;
    deque<int> d2;
    deque<int> d3;
    int score[3] = {0,0,0};
    
    d1.push_back(1);
    d1.push_back(2);
    d1.push_back(3);
    d1.push_back(4);
    d1.push_back(5);
    d2.push_back(2);
    d2.push_back(1);
    d2.push_back(2);
    d2.push_back(3);
    d2.push_back(2);
    d2.push_back(4);
    d2.push_back(2);
    d2.push_back(5);
    d3.push_back(3);
    d3.push_back(3);
    d3.push_back(1);
    d3.push_back(1);
    d3.push_back(2);
    d3.push_back(2);
    d3.push_back(4);
    d3.push_back(4);
    d3.push_back(5);
    d3.push_back(5);
    
    
    for(int i = 0; i<answers.size(); i++){
        int num1 = d1.front();
        d1.pop_front();
        d1.push_back(num1);
        int num2 = d2.front();
        d2.pop_front();
        d2.push_back(num2);
        int num3 = d3.front();
        d3.pop_front();
        d3.push_back(num3);
        if(num1==answers[i]){
            score[0]++;
        }
        if(num2==answers[i]){
            score[1]++;
        }
        if(num3==answers[i]){
            score[2]++;
        }
    }
    int m = max({score[0],score[1],score[2]});
    for(int i =0; i<3; i++){
        if(m==score[i]){
            answer.push_back(i+1);
        }
    }
    return answer;
}