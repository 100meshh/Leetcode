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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
        stack<bool>st1;
        vector<int>ans;
        if(!root) return ans;

        st.push(root);
        st1.push(0);

        while(!st.empty()){
            TreeNode* temp = st.top();
            st.pop();

            bool flag=st1.top();
            st1.pop();

            if(!flag){
                if(temp->right) {
                    st.push(temp->right);
                    st1.push(0);
                }
                st.push(temp);
                st1.push(1);

                if(temp->left){
                    st.push(temp->left);
                    st1.push(0);
                }
            }
            else{
            ans.push_back(temp->val);
            }
        }
        return ans;
    }
};