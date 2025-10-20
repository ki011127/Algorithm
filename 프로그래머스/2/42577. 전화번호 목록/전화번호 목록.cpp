#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_set<string> s;
    sort(phone_book.begin(), phone_book.end(), [](const string &a, const string &b){
       if(a.length()!=b.length()){
           return a.length()<b.length();
       }
       else{
           return a<b;
       }
    });
    for(int i = 0; i<phone_book.size(); i++){
        string number = phone_book[i];
        for(int j =1; j<number.length(); j++){
            string sub = number.substr(0,j);
            if(s.find(sub)!=s.end()){
                return false;
            }
        }
        s.insert(number);
    }
    return answer;
}