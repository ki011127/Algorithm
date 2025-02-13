#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long dist[101][101];
    fill(dist[0], dist[101], LLONG_MAX);
    for(int i= 1; i<=100; i++){
        dist[i][i] = 0;
    }
    
    int n;
    cin >> n;
    
    int m;
    cin >> m;
    for(int i =0; i<m;i++){
        int a,b;
        long long c;
        cin >>a>>b>>c;
        dist[a][b] = min(dist[a][b],c);
    }
    for(int k = 1; k<=n; k++){
        for(int i = 1; i<=n;i++){
            for(int j = 1; j<=n; j++){
                if(dist[i][k]!=LLONG_MAX && dist[k][j]!=LLONG_MAX && dist[i][j]>dist[i][k]+dist[k][j]){
                    dist[i][j] = dist[i][k]+dist[k][j];
                }
            }
        }
    }

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            if(dist[i][j]==LLONG_MAX){
                cout << "0 ";
            }
            else{
                cout << dist[i][j] << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}