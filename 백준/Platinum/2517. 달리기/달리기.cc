#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int N;
vector<int> v;
vector<int> sort_v;
map<int, int> m;
int leaf_count = 1;
int leaf_pointer;
int *tree;
bool comp(int a, int b){
    return a>b;
}

void init_tree(){
    while(N>leaf_count){
        leaf_count*=2;
    }
    tree = new int[leaf_count*2];
    leaf_pointer=leaf_count;
    for(int i = 0; i<leaf_count*2; i++){
        tree[i] = 0;
    }
}

void update_tree(int idx){
    int tree_index = idx+leaf_pointer;
    tree[tree_index] = 1;
    tree_index/=2;
    while(tree_index>0){
        tree[tree_index] = tree[tree_index*2] + tree[tree_index*2+1];
        tree_index/=2;
    }
}

int query(int t_idx){
    int l = leaf_pointer;
    int r = leaf_pointer+t_idx-1;
    int rank = 0;
    while(l<=r){
        if(l%2==1){
            rank+=tree[l];
            l++;
        }
        if(r%2==0){
            rank+=tree[r];
            r--;
        }
        l/=2;
        r/=2;
    }
    return rank+1;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 0; i<N; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    init_tree();
    sort_v = v;
    sort(sort_v.begin(), sort_v.end(), comp);
    for(auto i=0; i<sort_v.size();i++){
        m[sort_v[i]] = i;
    }
    for(int i = 0; i<v.size(); i++){
        update_tree(m[v[i]]);
        cout << query(m[v[i]]) << "\n";
    }
    return 0;
}