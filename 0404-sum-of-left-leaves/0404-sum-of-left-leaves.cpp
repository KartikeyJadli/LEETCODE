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
    int sumOfLeftLeaves(TreeNode* root, bool branch){
        if(root == NULL){
            return 0;
        }

        else if(root->left == NULL && root->right == NULL){
            if(branch == true){
                return root->val;
            }

            else{
                return 0;
            }
        }

        else{
            return sumOfLeftLeaves(root->left,true) + sumOfLeftLeaves(root->right,false);
        }
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int sum = sumOfLeftLeaves(root,false);
        return sum;
    }
};