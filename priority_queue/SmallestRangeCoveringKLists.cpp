#include<bits/stdc++.h>

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        auto compare = [](vector<int>& lhs, vector<int>& rhs) {return lhs[0] > rhs[0];};
        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> pqLists(compare);

        
        int left = nums[0][0], right = nums[0][0];
        for (int i=0; i<nums.size(); i++) {
            // vector<int> it{nums[0][i], i, 0};
            left = min(nums[i][0], left);
            right = max(nums[i][0], right);
            pqLists.push({nums[i][0], i, 0});
        }

        vector<int> res = {left, right};

        while (true) {
            auto v = pqLists.top();
            pqLists.pop();
            v[2] += 1;
            if (v[2] == nums[v[1]].size()) {
                break;
            }
            int newEle = nums[v[1]][v[2]];
            pqLists.push({newEle, v[1], v[2]});
            right = max(newEle, right);
            left = min(right, pqLists.top()[0]);

            if (right - left < res[1] - res[0]) {
                res = {left, right};
            }
        }

        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> nums{{4,10,15,24,26}, {0,9,12,20}, {5,18,22,30}};
    s.smallestRange(nums);
}