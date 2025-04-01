#include <string>
#include <iostream>
#include <map>
using namespace std;
map<string, string> road;
int solution(string dirs) {
    int x = 0;
    int y = 0;
    int answer = 0;
    for(int i = 0; i<dirs.length(); i++){
        if(dirs[i]=='L'){
            if(x-1<-5){
                continue;
            }
            else{
                string dir1 = road[to_string(x)+to_string(y)];
                string dir2 = road[to_string(x-1)+to_string(y)];
                if(!(dir1.find("L")!=string::npos || dir2.find("R")!=string::npos)){
                    road[to_string(x)+to_string(y)] = road[to_string(x)+to_string(y)] + "L";
                    answer++;
                }
                x = x-1;
            }
        }
        else if(dirs[i]=='R'){
            if(x+1>5){
                continue;
            }
            else{
                string dir1 = road[to_string(x)+to_string(y)];
                string dir2 = road[to_string(x+1)+to_string(y)];
                if(!(dir1.find("R")!=string::npos || dir2.find("L")!=string::npos)){
                    road[to_string(x)+to_string(y)] = road[to_string(x)+to_string(y)] + "R";
                    answer++;
                }
                x = x+1;
            }
        }
        else if(dirs[i]=='D'){
            if(y-1<-5){
                continue;
            }
            else{
                string dir1 = road[to_string(x)+to_string(y)];
                string dir2 = road[to_string(x)+to_string(y-1)];
                if(!(dir1.find("D")!=string::npos || dir2.find("U")!=string::npos)){
                    road[to_string(x)+to_string(y)] = road[to_string(x)+to_string(y)] + "D";
                    answer++;
                }
                y = y-1;
            }
        }
        else{
            if(y+1>5){
                continue;
            }
            else{
                string dir1 = road[to_string(x)+to_string(y)];
                string dir2 = road[to_string(x)+to_string(y+1)];
                if(!(dir1.find("U")!=string::npos || dir2.find("D")!=string::npos)){
                    road[to_string(x)+to_string(y)] = road[to_string(x)+to_string(y)] + "U";
                    answer++;
                }
                y = y+1;
            }
        }
    }
    

    return answer;
}