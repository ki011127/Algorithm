#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int arr[100000];
int *tree;
int leaf_pointer;
int leaf_count;

void init_tree(int n){
    leaf_count = 1;
    while(n>leaf_count){
        leaf_count = leaf_count << 1;
    }
    tree = new int[leaf_count*2];
    leaf_pointer = leaf_count;

    int i = leaf_pointer;
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    // for(int i = 0; i<n; i++){
    //     cout << arr[i] << " ";
    // }
    // cout << "\n";
    for(;i<leaf_pointer+n;i++){
        tree[i] = i-leaf_pointer;
    }
    for(;i<leaf_count*2; i++){
        tree[i] = 0;
    }
    for(i=leaf_pointer-1; i>0; i--){
        if(arr[tree[i*2]]<=arr[tree[i*2+1]]){
            tree[i] = tree[i*2];
        }
        else{
            tree[i] = tree[i*2+1];
        }
    }
}

long long query(int start, int end){
    if(start>end){
        return 0;
    }
    int l = start+leaf_pointer;
    int r = end+leaf_pointer;
    int min_val = INT_MAX;
    int min_val_index;
    while(l<=r){
        if(l%2==1){
            if(min_val>arr[tree[l]]){
                min_val = arr[tree[l]];
                min_val_index = tree[l];
            }
            l++;
        }
        if(r%2==0){
            if(min_val>arr[tree[r]]){
                min_val = arr[tree[r]];
                min_val_index = tree[r];
            }
            r--;
        }
        l/=2;
        r/=2;
    }

    return max((long long)min_val*(end-start+1),max(query(start, min_val_index-1),query(min_val_index+1,end)));

}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    while(n!=0){
        init_tree(n);
        cout << query(0,n-1) << "\n";
        cin >> n;
        delete [] tree;
    }
    
    return 0;
}