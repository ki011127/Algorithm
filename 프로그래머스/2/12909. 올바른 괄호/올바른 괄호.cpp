#include<string>
#include <iostream>
#include <queue>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    deque<char> stack;
    for(int i = 0; i<s.length(); i++){
        if(s[i]=='('){
            stack.push_back(s[i]);
        }
        else{
            if(stack.empty()){
                return false;
            }
            char c = stack.back();
            stack.pop_back();
            if(c!='('){
                answer= false;
                break;
            }
        }
    }
    if(!stack.empty()){
        return false;
    }

    return answer;
}