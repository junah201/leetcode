// 46. Permutations
// 02/24/2022 22:50	Accepted	4 ms	7.7 MB	cpp

#include <vector>
using namespace std;

int N;

vector <int> selected;
vector <int> check;
vector<vector<int>> result;

class Solution {
public:
    void get(int idx, vector<int>& nums) {
        if(idx == N) {
            result.push_back(selected);
            return;
        }
        for(int i=0;i<N;i++) {
            if(!check[i]) {
                selected[idx] = nums[i];
                check[i] = 1;
                get(idx+1, nums);
                check[i] = 0;
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        N = nums.size();
        result.resize(0);
        selected.resize(N, 0);
        check.resize(N, 0);
        get(0, nums);
        return result;
    }
};