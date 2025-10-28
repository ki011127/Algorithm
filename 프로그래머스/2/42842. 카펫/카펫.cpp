#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int s = brown+yellow;
    for(int w = (int)sqrt(s); s/w>=3; w++){
        int h = s/w;
        if(s%w!=0 || w<h){
            continue;
        }
        else{
            if(yellow==(h-2)*(w-2) && brown==h*2+w*2-4){
                answer.push_back(w);
                answer.push_back(h);
            }
        }
    }
    return answer;
}