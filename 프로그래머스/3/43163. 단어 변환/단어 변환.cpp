#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Node{
    string  word;
    int c;
};

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    if(find(words.begin(), words.end(), target)==words.end()){
        return answer;
    }
    
    vector<int> count(words.size(),0);
    deque<Node> dq;
    for(int i = 0; i<words.size(); i++){
        int num = 0;
        for(int idx = 0; idx<begin.length(); idx++){
            if(begin[idx]!=words[i][idx]){
                num++;
            }
            if(num>=2){
                break;
            }
        }
        if(num==1){
            dq.push_back({words[i], 1});
            count[i]=1;
            if(words[i]==target){
                return 1;
            }
        }
    }
    answer++;
    while(!dq.empty()){
        Node cur_word = dq.front();
        dq.pop_front();
        
        for(int i = 0; i<words.size(); i++){
            int num = 0;
            if(count[i]!=0){
                continue;
            }
            for(int idx = 0; idx<cur_word.word.length(); idx++){
                if(cur_word.word[idx]!=words[i][idx]){
                    num++;
                }
                if(num>=2){
                    break;
                }
            }
            if(num==1){
                dq.push_back({words[i], cur_word.c+1});
                count[i]=cur_word.c+1;
                if(words[i]==target){
                    return cur_word.c+1;
                }
            }
        }
        
    }
    
    return answer;
}