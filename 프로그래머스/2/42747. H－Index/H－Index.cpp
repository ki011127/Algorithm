#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end(), greater<int>());
    for(int i = min((int)citations.size(), citations[0]); i>=0; i--){
        if(citations[i-1]>=i){
            return i;
        }
    }
}