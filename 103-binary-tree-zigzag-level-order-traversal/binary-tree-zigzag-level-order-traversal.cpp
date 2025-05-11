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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root) return ans;

        stack<TreeNode*>st1,st2;
        st1.push(root);
        while(!st1.empty() || !st2.empty()){
            // R to L
          if(!st1.empty())
            {
                vector<int>level;
                
                while(!st1.empty())
                {
                    TreeNode* temp =st1.top();
                    st1.pop();
                    level.push_back(temp->val);
                    if(temp->left) st2.push(temp->left);
                    if(temp->right) st2.push(temp->right);
                }
                ans.push_back(level);
            } 
          else
          {
            vector<int>level;
            
            while(!st2.empty())
            {
                TreeNode* temp =st2.top();
                st2.pop();
                level.push_back(temp->val);
                if(temp->right) st1.push(temp->right);
                if(temp->left) st1.push(temp->left);
            }
            ans.push_back(level);
          } 
        }
        return ans;
    }
};