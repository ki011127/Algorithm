#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(),A.end(), greater<>());
    sort(B.begin(),B.end(), greater<>());
    int j = 0;
    for(int i = 0; i<A.size(); i++){
        int num = A[i];
        if(num < B[j]){
            j++;
            answer++;
        }
        if(j==B.size()){
            break;
        }
    }
    
    
    return answer;
}