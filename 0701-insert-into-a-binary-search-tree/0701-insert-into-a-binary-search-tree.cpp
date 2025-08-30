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
void inodr(TreeNode* root,vector<int>&ans){
    if(!root)return;
    inodr(root->left,ans);
    ans.push_back(root->val);
    inodr(root->right,ans);
}
TreeNode* buildTree(vector<int>&ans,int start,int end){
    if(start>end)return NULL;
    int mid=start+(end-start)/2;
    TreeNode* node=new TreeNode(ans[mid]);
    node->left = buildTree(ans,start,mid-1);
    node->right = buildTree(ans,mid+1,end);
    return node;
}
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        vector<int>ans;
        inodr(root,ans);
        ans.push_back(val);
        sort(ans.begin(),ans.end());
        //array to bst
        int n=ans.size();
        return buildTree(ans,0,n-1);
    }
};