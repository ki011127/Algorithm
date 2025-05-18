#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

int temp_arr[501][501];

vector<int> solution(string s) {
    vector<int> answer;
    string sets = s.substr(1, s.length()-2);
    //cout << sets;
    int count = 0;
    while(sets.length()!=0){
        size_t start = sets.find("{");
        size_t end = sets.find("}");
        if(start!=string::npos && end!=string::npos){
            count++;
            string parsed_set = sets.substr(start+1, end-(start+1));
            
            size_t comma_pos = parsed_set.find(",");
            if(comma_pos==string::npos){
                temp_arr[0][0] = stoi(parsed_set);
            }
            else{
                vector<int> temp;
                while(comma_pos!=string::npos){
                    temp.push_back(stoi(parsed_set.substr(0,comma_pos)));
                    parsed_set = parsed_set.substr(comma_pos+1);
                    comma_pos = parsed_set.find(",");
                }
                temp.push_back(stoi(parsed_set));
                for(int i = 0; i<temp.size(); i++){
                    temp_arr[temp.size()-1][i] = temp[i];
                }
            }
            
            if(end+2>sets.length()){
                break;
            }
            sets = sets.substr(end+2);
        }
        else{
            break;
        }

    }
    unordered_set<int> used;
    for(int i =0; i<count; i++){
        for(int j =0; j<=i; j++){
            if(used.find(temp_arr[i][j])==used.end()){
                answer.push_back(temp_arr[i][j]);
                used.insert(temp_arr[i][j]);
            }
        }
    }
    
    
    
    
    return answer;
}