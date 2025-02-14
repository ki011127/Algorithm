#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;
pair<int, int> p[100000];
int lis[100000];
int trace[100000];
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    for(int i = 0; i<N; i++){
        int a,b;
        cin >> a >>b;
        p[i] = make_pair(a,b);
    }

    sort(p,p+N);

    lis[0] = p[0].second;
    int lis_last_idx=0;
    for(int i = 0; i<N; i++){
        if(lis[lis_last_idx]<p[i].second){
            lis[++lis_last_idx] = p[i].second;
            trace[i] = lis_last_idx;
        }
        else{
            int idx = lower_bound(lis,lis+lis_last_idx+1,p[i].second)-lis;
            lis[idx] = p[i].second;
            trace[i] = idx;
        }
    }
    deque<int> stack;
    cout << N-1-lis_last_idx << "\n";
    for(int i = N-1; i>=0; i--){
        if(lis_last_idx==trace[i]){
            p[i].second = 0;
            lis_last_idx--;
        }
    }
    for(int i = 0; i<N; i++){
        if(p[i].second!=0){
            cout << p[i].first << " ";
        }
    }

    return 0;
}