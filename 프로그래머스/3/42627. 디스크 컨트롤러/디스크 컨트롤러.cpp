#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct Work{
    int working_time;
    int id;
    int arrived_at;
    
    Work(int working_time, int id, int arrived_at){
        this->working_time = working_time;
        this->id = id;
        this->arrived_at = arrived_at;
    }
};

struct Compare{
    bool operator()(const Work& a, const Work& b) const {
        if(a.working_time==b.working_time){
            if(a.arrived_at==b.arrived_at){
                return a.id>b.id;
            }
            else{
                return a.arrived_at > b.arrived_at;
            }
        }
        else{
            return a.working_time>b.working_time;
        }
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    vector<Work> work;
    for(int i = 0; i<jobs.size(); i++){
        work.push_back(Work(jobs[i][1],i,jobs[i][0]));
    }
    sort(work.begin(), work.end(), [](const Work &a, const Work &b){
       return a.arrived_at < b.arrived_at;
    });
    priority_queue<Work, vector<Work>, Compare> pq;
    int turn_arround = 0;
    int cur_time = 0;
    int idx = 0;
    while(!(pq.empty() && idx>=work.size())){
        while(idx<work.size() && work[idx].arrived_at<=cur_time){
            pq.push(work[idx++]);
            
        }
        if(pq.empty()){
            cur_time++;
            continue;
        }
        
        Work add_work = pq.top();
        pq.pop();
        cur_time+=add_work.working_time;
        turn_arround+=(cur_time-add_work.arrived_at);
        
    }
    return turn_arround/work.size();
}