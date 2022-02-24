// 35. Search Insert Position
// 02/24/2022 21:59	Accepted	3 ms	9.5 MB	cpp

#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int mid;
        if(target > nums[nums.size()-1]) return nums.size();
        if(target < nums[0]) return 0;
        while(low <= high) {
            mid = (low + high) / 2;
            if(low == high) break;
            if(nums[mid] < target) {
                low = mid + 1;
            }
            else if(nums[mid] > target) {
                high = mid;
            }
            
            else return mid;
        }
        return mid;
    }
};