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
    TreeNode* deleteNode(TreeNode* root, int key) {
        //find node
        if(!root) return NULL;
        if(root->val>key){
            root->left=deleteNode(root->left,key);
            return root;
        }
        else if(root->val<key){
            root->right=deleteNode(root->right,key);
            return root;
        }
        else{
            //leaf node
            if(!root->left && !root->right){
                delete root;
                return NULL;
            }
            //1 child exist
            else if(!root->right){
                TreeNode* temp=root->left;
                delete root;
                return temp;
            }
            else if(!root->left){
                TreeNode* temp=root->right;
                delete root;
                return temp;
            }
            //2 child exist
            else{
                TreeNode* Child=root->left;
                TreeNode* Parent=root;
                while(Child->right){
                    Parent=Child;
                    Child=Child->right;
                }
                if(root!=Parent){
                    Parent->right=Child->left;
                    Child->left=root->left;
                    Child->right=root->right;
                    delete root;
                    return Child;
                }
                else{
                    Child->right=root->right;
                    delete root;
                    return Child;
                }
            }
        }
    }
};