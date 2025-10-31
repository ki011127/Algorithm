#include <string>
#include <vector>

using namespace std;

int answer;
int count = 0;
char alpha[5] = {'A', 'E', 'I', 'O', 'U'};

void find_word(string target, string cur){
    if(cur==target){
        answer = count;
        return;
    }
    if(cur.length()==5){
        return;
    }
    
    for(int i = 0; i<5; i++){
        count++;
        find_word(target, cur+alpha[i]);
    }
}

int solution(string word) {
    
    
    find_word(word, "");
    
    return answer;
}