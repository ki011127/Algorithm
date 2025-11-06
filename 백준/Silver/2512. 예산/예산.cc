#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;  

    vector<int> budgets(N);
    for (int i = 0; i < N; i++) {
        cin >> budgets[i];  // 
    }
    int M;
    cin >> M;
    int left = 0;
    int right = *max_element(budgets.begin(), budgets.end());
    int answer = 0;
    while(left<=right){
        int mid = (left+right)/2;

        long long total = 0;
        for(int i =0; i<N; i++){
            if(budgets[i]<=mid){
                total+=budgets[i];
            }
            else{
                total+=mid;
            }
        }
        if(total>M){
            right = mid-1;
        }
        else{
            left = mid+1;
            answer = mid;
        }
    }
    cout << answer;
    return 0;
}