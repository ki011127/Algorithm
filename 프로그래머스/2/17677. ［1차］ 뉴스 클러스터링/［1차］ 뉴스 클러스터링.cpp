#include <string>
#include <map>
#include <iostream>
using namespace std;

map<string, int> m1;

int solution(string str1, string str2) {
    int answer = 0;
    int intersect = 0;
    int uni = 0;
    for(int i = 0; i<str1.length()-1; i++){
        string s = str1.substr(i,2);
        if((!isalpha(s[0])) || (!isalpha(s[1]))){
            continue;
        }
        s[0] = tolower(s[0]);
        s[1] = tolower(s[1]);

        if(m1[s]){
            m1[s] = m1[s]+1;
        }
        else{
            m1[s] = 1;
        }
    }
    for(int i = 0; i<str2.length()-1; i++){
        string s = str2.substr(i,2);
        if((!isalpha(s[0])) || (!isalpha(s[1]))){
            continue;
        }
        s[0] = tolower(s[0]);
        s[1] = tolower(s[1]);

        if(m1[s]>0){
            intersect++;
            uni++;
            m1[s] = m1[s]-1;
        }
        else{
            uni++; 
        }
    }
    for(int i = 0; i<str1.length()-1; i++){
        string s = str1.substr(i,2);
        if((!isalpha(s[0])) || (!isalpha(s[1]))){
            continue;
        }
        s[0] = tolower(s[0]);
        s[1] = tolower(s[1]);
        if(m1[s]>0){

            uni += m1[s];
            m1[s] = 0;
        }
    }

    if(intersect==0 && uni==0){
        return 65536;
    }
    answer = (int)(((float)intersect/uni)*65536);
    
    return answer;
}