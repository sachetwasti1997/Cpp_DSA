#include<bits/stdc++.h>

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() == 1 || nums.size() == 2) {
            return 0;
        }
        int l = 0, r = l+1, prevDiff = nums[r] - nums[l];
        long res = 0;
        while (l <= nums.size() - 3) {
            r = l+1;
            int start = r-1;
            prevDiff = nums[r] - nums[l];
            while (r < nums.size() && prevDiff == nums[r] - nums[r-1]) {
                if (r-l+1 >= 3)
                    res++;
                r++;
            }
            l++;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums{1,2,3,4,8,5,7,9};
    cout<<s.numberOfArithmeticSlices(nums);
}