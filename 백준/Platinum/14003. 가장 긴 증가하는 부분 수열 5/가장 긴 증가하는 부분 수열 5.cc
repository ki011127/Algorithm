#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;
int A[1000000];
int trace[1000000];
int lis[1000000];
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;
    for(int i =0; i<N; i++){
        cin >> A[i];
    }
    lis[0] = A[0];
    int lis_last_idx = 0;
    for(int i =1; i<N;i++){
        if(A[i]>lis[lis_last_idx]){
            lis[++lis_last_idx] = A[i];
            trace[i] = lis_last_idx;
        }
        else{
            int idx = lower_bound(lis, lis+lis_last_idx+1, A[i])-lis;
            lis[idx] = A[i];
            trace[i] = idx;
        }
    }
    deque<int> stack;
    cout << lis_last_idx+1 << "\n";
    for(int i = N-1; i>=0 ; i--){
        if(lis_last_idx==trace[i]){
            lis_last_idx--;
            stack.push_back(A[i]);
        }
    }
    while(!stack.empty()){
        cout << stack.back() << " ";
        stack.pop_back();
    }
    return 0;

}