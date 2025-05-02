#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    
    int max_level = 100000;
    int min_level = 1;
    
    while(max_level>=min_level){
        int mid_level = (max_level+min_level)/2;
        long long total_time = times[0];
        for(int i = 1; i<diffs.size(); i++){
            long long temp_time;
            // if(mid_level == 2){
            //     cout << total_time << "\n";
            // }
            if(diffs[i]>mid_level){
                temp_time = (diffs[i]-mid_level)*(times[i-1] + times[i])+ times[i];
                total_time += temp_time;
            }
            else{
                temp_time = times[i];
                total_time+=temp_time;
            }
            if(total_time>limit){
                break;
            }
        }
        //cout << "level: " << mid_level << " total_time: " << total_time << "\n";
        if(total_time>limit){
            min_level = mid_level+1;
        }
        else{
            max_level = mid_level-1;
            answer = mid_level;
        }
    }
    
    return answer;
}