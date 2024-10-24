#include <bits/stdc++.h>
#include "TreeNode.h"

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long> maxHeap;
        queue<TreeNode*> temp;
        temp.push(root);
        int sz = temp.size();
        while(!temp.empty()) {
            long long sum = 0;
            for (int i = 0; i < sz; i++) {
                auto nd = temp.front();
                if (nd->left) temp.push(nd->left);
                if (nd->right) temp.push(nd->right);
                sum += nd->val;
                temp.pop();
            }
            sz = temp.size();
            maxHeap.push(sum);
        }
        if (k > maxHeap.size())
            return -1;
        long long res = -1;
        while (k > 0 && !maxHeap.empty()) {
            res = maxHeap.top();
            maxHeap.pop();
            k--;
        }
        return res;
    }
};

int main() {}