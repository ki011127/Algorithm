#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

long long num_of_spell[12];
long long sum_of_spell[12];
long long count_spell(int n){
    int fact = 26;
    long long num = 1;
    for(int i = n; i>0; i--){
        num*=fact;
    }
    return num;
}

string find_spell(long long n) {
    int i = 1;
    string target = "";
    for(; i<12; i++){
        if(sum_of_spell[i]>=n){
            break;
        }
    }
    
    n -= sum_of_spell[i-1];
    while(i>=2){
        char c = n/num_of_spell[i-1]+97;
        n = n%num_of_spell[i-1];
        if(n==0){
            c--;
            n=num_of_spell[i-1];
        }
        target+=c;
        i--;
    }
    char c = n/num_of_spell[i-1]+96;
    target+=c;
    return target;
}

string solution(long long n, vector<string> bans) {
    string answer = "";
    for(int i = 1; i<=11; i++){
        num_of_spell[i] = count_spell(i);
    }
    num_of_spell[0]=1;
    sum_of_spell[0]=0;
    sum_of_spell[1] = num_of_spell[1];
    for(int i = 2; i<=11; i++){
        sum_of_spell[i]=sum_of_spell[i-1]+num_of_spell[i];
    }
    string candidate = find_spell(n);
    sort(bans.begin(), bans.end(), [](const string &a, const string &b){
        if(a.length()!=b.length()){
            return a.size()<b.size();
        }
        else{
            return a<b;
        }
    });
    int len = candidate.length();
    for(int i = 0; i<bans.size(); i++){
        if(len>bans[i].length()){
            n++;
            candidate = find_spell(n);
        }
        else if(len==bans[i].length() && candidate>=bans[i]){
            n++;
            candidate = find_spell(n);
        }
    }
    return find_spell(n);
}

