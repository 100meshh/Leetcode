/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int helper(TreeNode* node, long long targetSum) {
        if (!node) return 0;
        int cnt = 0;
        if (node->val == targetSum) cnt++;
        cnt += helper(node->left, targetSum - node->val);
        cnt += helper(node->right, targetSum - node->val);
        return cnt;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;             // <-- crucial
        return helper(root, targetSum)+ pathSum(root->left, targetSum)+ pathSum(root->right, targetSum);
    }
};
