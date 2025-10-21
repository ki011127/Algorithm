#include <string>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(), numbers.end(), [](const int a, const int b){
        string a_str = to_string(a);
        string b_str = to_string(b);
        return a_str+b_str>b_str+a_str;
        
    });
    for(int i = 0; i<numbers.size(); i++){
        answer+=to_string(numbers[i]);
    }
    if(answer[0]=='0'){
        return "0";
    }
    return answer;
}