#include<bits/stdc++.h>
#include "TreeNode.h"

class Solution {
private:
    vector<int> calculateLevelSum(TreeNode *root) {
        vector<int> levelSum;
        levelSum.emplace_back(root->val);
        queue<TreeNode*> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            int sz = nodes.size(), sum = nodes.front()->val;
            for (int i=0; i<sz; i++) {
                auto tmp = nodes.front();
                if (tmp->left) {
                    nodes.push(tmp->left);
                    sum += tmp->left->val;
                }if (tmp->right) {
                    nodes.push(tmp->right);
                    sum += tmp->right->val;
                }
                nodes.pop();
            }
            levelSum.emplace_back(sum);
        }
        return levelSum;
    }
    void populateCousinSum(TreeNode* root, vector<int> sums) {
        queue<TreeNode*> nodes;
        if(root->left) nodes.push(root->left);
        if(root->right) nodes.push(root->right);
        int indx = 2;
        while (!nodes.empty() && indx < sums.size()) {
            int sz = nodes.size();
            for (int i=0; i<sz; i++) {
                auto& tmp = nodes.front();
                int currentSm = 0;
                if (tmp->left) {
                    nodes.push(tmp->left);
                    currentSm += tmp->left->val;
                }if (tmp->right) {
                    nodes.push(tmp->right);
                    currentSm += tmp->right->val;
                }
                if (tmp->left) tmp->left->val = sums[indx] - currentSm;
                if (tmp->right) tmp->right->val = sums[indx] - currentSm;
                nodes.pop();
            }
        }
    }
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        unordered_map<int, int> mp;
        auto temp = root;
        root->val = 0;
        if (root->right) root->right = 0;
        if (root->left) root->left = 0;
        vector<int> sums = calculateLevelSum(root);
        if (sums.size() == 1 || sums.size() == 2) {
            return root;
        }
        populateCousinSum(root, sums);
        return root;
    }
};

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(9);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(10);

    root->right->right = new TreeNode(7);

    Solution s;
    s.replaceValueInTree(root);
}