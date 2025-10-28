#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> m;
    for(int i = 0; i<participant.size(); i++){
        m[participant[i]]++;
    }
    for(int i = 0; i<completion.size(); i++){
        m[completion[i]]--;
        if(m[completion[i]]==0){
            m.erase(completion[i]);
        }
    }
    for(auto &p : m){
        return p.first;
    }
}