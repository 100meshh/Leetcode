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
bool helper(TreeNode* root, int targetSum){
    if(!root)return false;
    targetSum-=root->val;
    if(targetSum==0)return true;
    int lefty=helper(root->left,targetSum);
    int righty=helper(root->right,targetSum);

    return lefty||righty;
    
}
    bool hasPathSum(TreeNode* root, int targetSum) {
        return helper(root,targetSum);
        
    }
};