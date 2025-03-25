#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int mul(int num){
    int value = 2;
    int count = 0;
    while(pow(value,count)<=num){
        count++;
    }
    //cout << count;
    return count;
}

vector<int> solution(string s) {
    int zero_count = 0;
    for(int i = 0; i<s.length(); i++){
        if(s[i]=='0'){
            zero_count++;
        }
    }  
    int change_count = 0;
    int len = s.length()-zero_count;
    
    while(len!=1){
        int temp_len = len;
        int total = mul(len);
        int one_count= 0;
        while(temp_len!=0){
            int val = mul(temp_len);
            if(temp_len-pow(2,val-1)>=0){
                temp_len-=pow(2,val-1);
                one_count++;
            }
        }
        len = one_count;
        zero_count+=(total-one_count);
        change_count++;
    }
    
    vector<int> answer;
    answer.push_back(change_count+1);
    answer.push_back(zero_count);
    return answer;
}