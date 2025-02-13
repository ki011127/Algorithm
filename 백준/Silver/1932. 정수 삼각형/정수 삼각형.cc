#include <iostream>
#include <algorithm>
using namespace std;

int arr[500][500];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i<n; i++){
        for(int j = 0; j<=i; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = n-1; i>0; i--){
        for(int j =0; j<i; j++){
            arr[i-1][j] += max(arr[i][j],arr[i][j+1]);
        }
    }
    cout << arr[0][0];

    return 0;
}