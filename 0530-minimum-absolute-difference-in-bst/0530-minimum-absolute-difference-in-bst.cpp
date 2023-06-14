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
    int getMinimumDifference(TreeNode* root) {
        int ans=INT_MAX,prev=-1;
        inorder(root, ans,prev);
        return ans;
    }
    
    void inorder(TreeNode* root, int &ans, int &prev){
        if(root==NULL){
            return;
        }
        inorder(root->left,ans,prev);
        if(prev!=-1){
            ans=min(abs((root->val)-prev),ans);
        }
        prev=root->val;
        inorder(root->right,ans,prev);

    }
};