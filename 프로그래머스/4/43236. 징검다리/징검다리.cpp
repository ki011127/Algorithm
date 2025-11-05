#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    sort(rocks.begin(), rocks.end());
    rocks.push_back(distance);
    
    int left= 1;
    int right = distance;
    
    while(left<=right){
        int mid = (left+right)/2;
        int prev_rock=0;
        int count = 0;
        for(int rock : rocks) {
            if(rock-prev_rock < mid){
                count++;
            }
            else{
                prev_rock = rock;
            }
        }
        if(count>n){
            right = mid-1;
        }
        else{
            answer = mid;
            left = mid+1;
        }
        
    }
    
    return answer;
}