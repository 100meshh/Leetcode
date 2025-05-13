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
int find(vector<int>& inorder,int target,int start,int end){
    for(int i=start;i<=end;i++){
        if(inorder[i]==target)
        return i;
    }
    return -1;
}
TreeNode* Tree(vector<int>&inorder,vector<int>&preorder,int instart,int inend,int index){\
        if(instart>inend) return NULL;

        TreeNode* root = new TreeNode(preorder[index]);
        int pos=find(inorder,preorder[index],instart,inend);
        // index++;
        root->left=Tree(inorder,preorder,instart,pos-1,index+1);      
        root->right=Tree(inorder,preorder,pos+1,inend,index+(pos-instart)+1);  
        return root;   
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        return Tree(inorder,preorder,0,n-1,0);
        // int instart=0;
        // int n=preorder.size();
        // int inend=n-1;
        // int index=0;  
    }
};