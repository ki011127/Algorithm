#include <string>
#include <vector>
#include <deque>
#include <iostream>
using namespace std;

int correct(string u){
    deque<char> q;
    if(u[0]==')'){
        return 0;
    }
    for(int i =0; i<u.length(); i++){
        if(u[i]=='('){
            q.push_back(u[i]);
        }
        else{
            if(q.back()=='('){
                q.pop_back();
            }
            else{
                return 0;
            }
        }
    }
    if(q.size()==0){
        return 1;
    }
    else{
        return 0;
    }
}


string sol(string s){
    if(s.length()==0){
        return "";
    }
    int l_count = 0;
    int r_count = 0;
    string temp;
    if(s[0]=='('){
        l_count++;
    }
    else{
        r_count++;
    }
    int i = 1;
    while(l_count!=r_count){
        if(s[i]=='('){
            l_count++;
        }
        else{
            r_count++;
        }
        i++;
    }
    string u = s.substr(0,l_count+r_count);
    string v = s.substr(l_count+r_count);
    if(correct(u)){
        temp.append(u);
        temp.append(sol(v));
    }
    else{
        temp.append("(");
        temp.append(sol(v));
        temp.append(")");
        u = u.substr(1,u.length()-2);
        for(int i = 0; i<u.length(); i++){
            if(u[i]=='('){
                temp.append(")");
            }
            else{
                temp.append("(");
            }
        }
    }
    return temp;
}

string solution(string p) {
    
    string answer = "";
    answer.append(sol(p));
    
    
    return answer;
}