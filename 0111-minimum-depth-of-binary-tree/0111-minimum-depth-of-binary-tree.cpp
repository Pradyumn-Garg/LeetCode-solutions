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
    int minDepth(TreeNode* root) {
        queue <pair<TreeNode*,int>> q;
        if(root==NULL){
            return 0;
        }
        q.push({root,1});
        while(!q.empty()){
            if(q.front().first->left==NULL&&q.front().first->right==NULL){
                return q.front().second;
            }
            if(q.front().first->left!=NULL){
                q.push({q.front().first->left,q.front().second+1});
            }
            if(q.front().first->right!=NULL){
                q.push({q.front().first->right,q.front().second+1});
            }
            q.pop();
        }
        return -1;
    }
};