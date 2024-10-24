#include <bits/stdc++.h>
#include "TreeNode.h"

class Solution {
private:
    bool compare(TreeNode* root1, TreeNode* root2) {
        if (root1 == root2) {
            return true;
        }
        else if (!root1 || !root2) {
            return false;
        }
        else if (root1->val != root2->val) {
            return false;
        }

        bool res = compare(root1->left, root2->left) && compare(root1->right, root2->right);
        if (!res) {
            res = compare(root1->left, root2->right) && compare(root1->right, root2->left);
        }
        return res;
    }
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return compare(root1, root2);
    }
};

int main() {
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->left->left = new TreeNode(3);

    Solution s;
    cout<<s.flipEquiv(root1, root2)<<endl;
}