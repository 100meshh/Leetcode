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
int maxsum;
    int helper(TreeNode* root){
        if(!root)return 0;
        int lefts = max(0,helper(root->left));
        int rights = max(0,helper(root->right));
        int currentpathsum=root->val+lefts+rights;
        maxsum=max(maxsum,currentpathsum);
        return root->val+max(lefts,rights);
        
    }
    int maxPathSum(TreeNode* root) {
        maxsum=INT_MIN;
        helper(root);
        return maxsum;
    }
};