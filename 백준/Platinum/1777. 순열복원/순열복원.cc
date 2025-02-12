#include <iostream>

using namespace std;

int *tree;
int leaf_count=1;
int leaf_pointer;
void init_tree(int N){
    while(N>leaf_count){
        leaf_count = leaf_count << 1;
    }
    leaf_pointer = leaf_count;
    tree = new int[leaf_count*2];
    int i = leaf_pointer;
    for(;i<leaf_pointer+N; i++){
        tree[i] = 1;
    }
    for(;i<leaf_count*2;i++){
        tree[i] = 0;
    }
    for(i = leaf_pointer-1; i>0; i--){
        tree[i] = tree[i*2]+tree[i*2+1];
    }
}
int *inverse_arr;
int *answer;

void update(int a){
    int idx = leaf_pointer+a;
    tree[idx] = 0;
    idx/=2;
    while(idx>0){
        tree[idx] = tree[idx*2] + tree[idx*2+1];
        idx/=2;
    }
}

int query(int a){
    int idx = 1;
    while(idx<leaf_pointer){
        if(tree[idx*2+1]>=a){
            idx = idx*2+1;
        }
        else{
            a = a-tree[idx*2+1];
            idx = idx*2;
        }
    }
    return idx-leaf_pointer;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    inverse_arr = new int[N+1];
    answer = new int[N];
    for(int i =1; i<=N; i++){
        cin >> inverse_arr[i];
    }
    init_tree(N);
    for(int i = N; i>0; i--){
        int idx = query(inverse_arr[i]+1);
        answer[idx]=i;
        update(idx);
    }
    for(int i = 0; i<N; i++){
        cout << answer[i] << " ";
    }
    return 0;
}