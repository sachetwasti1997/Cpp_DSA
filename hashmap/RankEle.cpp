#include<bits/stdc++.h>

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, vector<int>> posMap;
        int k = 0;
        for (int i: arr) {
            posMap[i].emplace_back(k++); 
        }
        vector<int> arr1(arr.begin(), arr.end());

        sort(arr.begin(), arr.end());

        int rnk = 1;
        for(auto& [k, v]: posMap) {
            for(int j: v) {
                arr1[j] = rnk;
            }
            rnk++;
        }

        return arr1;
    }
};

int main() {
    Solution s;
    vector<int> arr{37,12,28,9,100,56,80,5,12};
    auto t = s.arrayRankTransform(arr);
    for (int i : t)
    {
        cout<<i<<" ";
    }
    
}