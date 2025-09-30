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
void inoder(TreeNode *root,vector<int>&ans){
      if(!root) return;
      inoder(root->left,ans);
      ans.push_back(root->val);
      inoder(root->right,ans);
  }
    int rangeSumBST(TreeNode* root, int low, int high) {
       vector<int>ans;
        inoder(root,ans);
        
        int ret=0;
        int n=ans.size();
         for (int i = 0; i < n; i++) {
            if (ans[i] >= low && ans[i] <= high) {
                ret+=ans[i];
            }
        }
        return ret; 
    }
};