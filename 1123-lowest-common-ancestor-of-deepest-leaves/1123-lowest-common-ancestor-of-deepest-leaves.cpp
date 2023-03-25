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
    unordered_set <TreeNode*> s;
    TreeNode *ans=NULL;
    int size;
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root->left&&!root->right){
            return root;
        }
        queue <TreeNode*> q,temp;
        q.push(root);
        while(!q.empty()){
            temp=q;
            int n=q.size();
            while(n!=0){
                if(q.front()->left){
                    q.push(q.front()->left);
                }
                if(q.front()->right){
                    q.push(q.front()->right);
                }
                q.pop();
                n--;
            }
        }
        while(!temp.empty()){
            s.insert(temp.front());
            temp.pop();
        }
        size=s.size();
        rec(root);
        return ans;
    }
    
    
    int rec(TreeNode* root){
//         if(!root || ans){
//             return 0;
//         }
//         if(s.find(root)!=s.end()){
//             return 1;
//         }

//         int left=rec(root->left);
//         int right = rec(root->right);
        
//         if(left+right==size&&!ans){
//             ans=root;
//         }
        
//         return left+right;
        
        if(!root || ans) return 0;
        
        int left = rec(root->left);
        int right = rec(root->right);
        
        int x = left+right;
        
        if(s.find(root)!=s.end())
        x++;
        
        if(x==size && !ans)
        ans = root;
        
        return x;
    }
    
};