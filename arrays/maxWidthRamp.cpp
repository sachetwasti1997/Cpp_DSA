#include<bits/stdc++.h>

class MaxWidthRamp {
public:
    int maxWidthRamp(vector<int>& nums) {
        if (nums.size() == 2 && nums[0] < nums[1]) {
            return 1;
        }
        vector<int> maxRight (nums.size(), 0);
        int maxNum = nums[nums.size()-1];
        maxRight[nums.size()-1] = maxNum;
        for (int i = nums.size()-2; i >= 0; i--)
        {
            if (maxNum < nums[i]) {
                maxNum = nums[i];
                maxRight[i] = nums[i];
                continue;
            }
            maxRight[i] = maxNum;
        }
        int l = 0, r = 0, maxRamp = 0;
        while (r < nums.size())
        {
            while (maxRight[r] < nums[l]) {
                l++;
            }
            maxRamp = max(maxRamp, r-l);
            r++;
        }
        
        return maxRamp;
    }
};


int main() {
    MaxWidthRamp m;
    vector<int> tmp{2,2,1};
    cout<<m.maxWidthRamp(tmp)<<endl;
}