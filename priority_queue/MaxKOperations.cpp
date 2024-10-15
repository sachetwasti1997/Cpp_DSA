#include<bits/stdc++.h>

#define ll long long

class MaxKOperations {
public:
    ll maxKelements(vector<int>& nums, int k) {
        priority_queue<int> maxEle;
        for (int i=0; i<nums.size(); i++) {
            maxEle.push(nums[i]);
        }
        int i=0;
        ll res = 0;
        while (i < k) {
            int t = maxEle.top();
            res += t;
            maxEle.pop();
            maxEle.push(ceil((double)t / 3));
            i++;
        }
        return res;
    }
};

int main() {
    MaxKOperations m;
    vector<int> nums{1,10,3,3,3};
    cout<<m.maxKelements(nums, 3)<<endl;
    double t = (double) 10 / 3;
    // cout<<t<<ceil(t);
}