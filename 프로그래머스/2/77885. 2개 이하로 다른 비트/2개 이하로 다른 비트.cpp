#include <string>
#include <vector>
#include <iostream>

using namespace std;


vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(int i =0; i<numbers.size(); i++){
        if(numbers[i]%2==0){
            answer.push_back(numbers[i]+1);
        }
        else{
            long long bit = 1;
            while ((numbers[i] & bit) != 0) {
                bit <<= 1;
            }
            answer.push_back(numbers[i] + bit - (bit >> 1));
        }
    }
    
    
    return answer;
}