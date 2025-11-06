#include<iostream>

using namespace std;

int main(void){
    int H,W,N,M;
    cin >> H >> W >> N >> M;

    int h = (H-1)/(1+N) + 1;
    int w = (W-1)/(1+M) + 1;

    cout << h*w;

    return 0;
}