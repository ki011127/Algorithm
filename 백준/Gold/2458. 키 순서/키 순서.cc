#include <iostream>
#include <limits.h>
using namespace std;

int dist[501][501];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    fill(dist[0],dist[501],INT_MAX);
    
    int N,M;
    cin >> N >> M;
    for(int i =1; i<=N; i++){
        dist[i][i] = 0;
    }
    for(int i = 0; i<M; i++){
        int a, b;
        cin >>a>> b;
        dist[a][b] = 1;
    }

    for(int k = 1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j = 1; j<=N; j++){
                if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX && dist[i][j]>dist[i][k]+dist[k][j]){
                    dist[i][j] = dist[i][k]+dist[k][j];
                }
            }
        }
    }
    int count = 0;
    
    for(int i = 1; i<=N;i++){
        int flag = 1;
        for(int j =1; j<=N; j++){
            if(dist[i][j]==INT_MAX && dist[j][i]==INT_MAX){
                flag =0;
                break;
            }
        }
        if(flag==1){
            count++;
        }
        flag = 1;
    }

    cout << count;
    return 0;
}