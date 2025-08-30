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
TreeNode* leftview(TreeNode* root){
    if(!root) return root;

    queue<TreeNode*>q;
    q.push(root);
    TreeNode* leftmost=root;

    while(!q.empty()){
        int size=q.size();
        leftmost=q.front();
            while(size--){
                TreeNode* node=q.front();
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }

    }
    return leftmost;
}
    int findBottomLeftValue(TreeNode* root) {
        TreeNode* node= leftview(root);
        return node->val;
    }
};