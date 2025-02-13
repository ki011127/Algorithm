#include <iostream>

using namespace std;
int N;
int leaf_count=1;
int leaf_pointer;
int *tree;

void init_tree(){
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
        tree[i] = tree[i*2] + tree[i*2+1];
    }
}

int query(int target){
    int idx = 1;
    while(idx<leaf_pointer){
        if(target>tree[idx*2]){
            target-=tree[idx*2];
            idx = idx*2+1;
        }
        else{
            idx = idx*2;
        }
    }

    int update_idx = idx;
    tree[update_idx] = 0;
    update_idx/=2;
    while(update_idx>0){
        tree[update_idx] = tree[update_idx*2] + tree[update_idx*2+1];
        update_idx/=2;
    }

    return idx-leaf_pointer;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    int *arr = new int[N];
    for(int i = 0; i<N; i++){
        cin >> arr[i];
    }
    init_tree();
    int *answer = new int[N];
    for(int i =0; i<N; i++){
        int idx = query(arr[i]+1);
        answer[idx] = i+1;
    }
    for(int i = 0; i<N; i++){
        cout << answer[i] << "\n";
    }
    return 0;
}