#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<string> channels(N);
    for (int i = 0; i < N; i++)
        cin >> channels[i];

    string answer = "";
    int pos1 = 0, pos2 = 0;

    for(int i = 0; i<N; i++){
        if(channels[i]=="KBS1"){
            pos1 = i;
            break;
        }
    }

    for(int i = 0; i<N; i++){
        if(channels[i]=="KBS2"){
            pos2 = i;
            break;
        }
    }

    for(int i = 0; i<pos1; i++){
        answer+="1";
    }
    for(int i = 0; i<pos1; i++){
        answer+="4";
    }

    if(pos2<pos1){
        pos2+=1;
    }
    for(int j =0; j<pos2; j++){
        answer+="1";
    }
    for(int j = 1; j<pos2; j++){
        answer+="4";
    }
    

    cout << answer;
    return 0;
}
