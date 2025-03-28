#include <string>
#include <vector>
#include <iostream>
#include <deque>
using namespace std;

int solution(string s) {
    deque<char> stack;
    int answer = 0;
    for(int i = 0; i<s.length(); i++){
        for(int j = i; j < i+s.length(); j++){
            int index;
            if(j>=s.length()){
                index = j-s.length();
            }
            else{
                index = j;
            }
            //cout << index << "\n";
            if(s[index]=='{' || s[index]=='(' || s[index]=='['){
                stack.push_back(s[index]);
            }
            else if(stack.size()!=0){
                if(s[index]=='}'){
                    if(stack.back()!='{'){
                        break;
                    }
                    else{
                        stack.pop_back();
                    }
                }
                else if(s[index]==')'){
                    if(stack.back()!='('){
                        break;
                    }
                    else{
                        stack.pop_back();
                    }
                }
                else if(s[index]==']'){
                    if(stack.back()!='['){
                        break;
                    }
                    else{
                        stack.pop_back();
                    }
                }
            }
            else{
                answer--;
                break;
            }
        }
        if(stack.size()==0){
            answer++;
        }
        stack.clear();
    }
    
    return answer;
}