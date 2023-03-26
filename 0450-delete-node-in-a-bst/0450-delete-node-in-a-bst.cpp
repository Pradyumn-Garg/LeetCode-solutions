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
	auto node = root;
	if(!node) return NULL;

	if(key > node->val) node->right = deleteNode(node->right, key);
	else if(key < node->val) node->left = deleteNode(node->left, key);

	//Now, when we have to delete the root i.e. when root->val == key
	else{
		if(!node -> left && !node->right) return NULL;
		if(!node -> left) return node->right;
		else if(!node -> right) return node->left;

		//when both left and right exist -> find minimum (mini) on right and attach root->left subtree to mini->left and return root->right.
		else{
			auto mini = node -> right;
			while(mini->left) mini = mini -> left;

			mini->left = node->left;
			return node->right;
		}
	}
	return node;
}
};