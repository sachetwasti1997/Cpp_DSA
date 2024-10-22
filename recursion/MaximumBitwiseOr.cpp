#include<bits/stdc++.h>

class Solution {
private:
    int countMaxOrSubsetsRec(vector<int>& nums, int i, int acc, int maxOr) {
        if (i >= nums.size()) {
            return acc == maxOr ? 1 : 0;
        }
        int excluding = countMaxOrSubsetsRec(nums, i+1, acc, maxOr);
        int including = countMaxOrSubsetsRec(nums, i+1, acc|nums[i], maxOr);

        return including+excluding;
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for (int i: nums) {
            maxOr |= i;
        }  
        cout<<maxOr<<endl; 
        return countMaxOrSubsetsRec(nums, 0, 0, maxOr);
    }
};

int main() {
    Solution s;
    vector<int> nums {3,1};
    cout<<s.countMaxOrSubsets(nums)<<endl;
}