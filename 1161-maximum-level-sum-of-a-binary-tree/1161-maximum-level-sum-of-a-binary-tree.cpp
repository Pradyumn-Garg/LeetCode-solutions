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
    int maxLevelSum(TreeNode* root) {
        int ans=1,clevel=1,curr=0,max=root->val;
        queue <TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            if(q.front()==NULL){
                clevel++;
                if(curr>max&&q.size()!=1){
                    ans=clevel;
                    max=curr;
                }
                if(q.size()!=1){
                    q.push(NULL);
                }
                q.pop();
                curr=0;
                continue;
            }
            auto a=q.front();
            if(a->left!=NULL){
                q.push(a->left);
                curr+=a->left->val;
            }
            if(a->right!=NULL){
                q.push(a->right);
                curr+=a->right->val;
            }
            q.pop();
        }
        return ans;
    }
};