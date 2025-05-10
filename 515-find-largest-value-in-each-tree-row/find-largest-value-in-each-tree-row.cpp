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
    vector<int> largestValues(TreeNode* root) {
        vector<int>ans;
        if(!root) return ans;

        queue<TreeNode*>q;
        q.push(root);

        // TreeNode* temp;
        while(!q.empty()){
            int size=q.size();
            int level=INT_MIN;

            for(int i=0;i<size;i++){
                TreeNode* temp =q.front();
                q.pop();
                int scout=temp->val;
                level=max(level,scout);

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            ans.push_back(level);
        }
        return ans;
        
    }
};