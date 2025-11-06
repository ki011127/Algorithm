#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    string s;
    cin >> s;
    int a_count = count(s.begin(),s.end(),'a');
    int answer = s.length()-a_count;
    for(int i =0; i<s.length(); i++){
        int b_count = 0;
        for(int j = 0; j<a_count; j++){
            if(s[(j+i)%s.length()]=='b'){
                b_count++;
            }
        }
        answer = min(answer, b_count);
    }
    cout << answer;
    return 0;
}