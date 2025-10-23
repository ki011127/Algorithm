#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<int> s;
unordered_set<int> s2;
bool isPrime(int num){
    if(num==1 || num==0){
        return false;
    }
    for(int i = 2; i*i<=num; i++){
        if(num!=i && num%i==0){
            return false;
        }
    }
    return true;
}

void solve(const string &numbers, string new_number, int max_length){
    if(new_number.length()==max_length){
        int num = stoi(new_number);
        if(isPrime(num)){
            if(!s.count(num)){
                s.insert(num);
            }
        }
        return;
    }
    
    for(int i = 0; i<numbers.length(); i++){
        if(s2.count(i)){
            continue;
        }
        s2.insert(i);
        solve(numbers, new_number+numbers[i], max_length);
        s2.erase(i);
    }
}

int solution(string numbers) {
    for(int i = 1; i<=numbers.length(); i++){
        solve(numbers, "", i);
    }
    
    return s.size();
}