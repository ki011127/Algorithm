#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int max_poket = nums.size()/2;
    set<int> s;
    for(int i =0; i<nums.size(); i++){
        s.insert(nums[i]);
        if(s.size()==max_poket){
            return max_poket;
        }
    }
    
    return s.size();
}