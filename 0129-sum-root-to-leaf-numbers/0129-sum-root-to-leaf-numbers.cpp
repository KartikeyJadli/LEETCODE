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
    int sum(TreeNode *root,int current){
        if(root == NULL){
            return 0;
        }

        if(root->left == NULL && root->right == NULL){
            return current*10 + root->val;
        }

        return sum(root->left,current*10 + root->val) + sum(root->right,current*10 + root->val);

        // return current;
    }

    int sumNumbers(TreeNode* root) {
        int current = 0;
        return sum(root,current);
    }
};