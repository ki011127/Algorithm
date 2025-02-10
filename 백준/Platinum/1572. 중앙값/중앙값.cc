#include <iostream>

using namespace std;
int tree[65536*4] = {0, };
int leaf_count = 65536*2;
int arr[250001] = {0,};
int leaf_pointer = leaf_count;
void init_tree(int K);
void update(int num, int remove_idx);
int query(int K);
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N,K;
    int idx = 0;
    cin >> N >> K;
    init_tree(K);
    long long result = 0;
    result += query(K);
    for(int i = 0; i<N-K; i++){
        int num;
        cin >> num;
        arr[K+i] = num;
        update(num, idx);
        idx++;
        result += query(K);
    }
    cout << result;
    return 0;
}

void init_tree(int K){
    for(int i = 0; i<K;i++){
        cin >> arr[i];
        tree[arr[i]+leaf_pointer]++;
    }
    for(int i = leaf_pointer-1; i>0; i--){
        tree[i] = tree[i*2] + tree[i*2+1];
    }
}

void update(int num, int remove_idx){
    int index = leaf_pointer+num;
    tree[index]++;
    int remove_index = leaf_pointer+arr[remove_idx];
    index/=2;
    while(index>0){
        tree[index] = tree[index*2] + tree[index*2+1];
        index/=2;
    }
    tree[remove_index]--;
    remove_index/=2;
    while(remove_index>0){
        tree[remove_index] = tree[remove_index*2] + tree[remove_index*2+1];
        remove_index/=2;
    }
}

int query(int K){
    int target = (K+1)/2;
    int idx = 1;
    while(idx<leaf_count){
        if(tree[idx*2]>=target){
            idx*=2;
        }
        else{
            target = target-tree[idx*2];
            idx = idx*2 +1;
        }
    }
    return idx-leaf_count;
}

