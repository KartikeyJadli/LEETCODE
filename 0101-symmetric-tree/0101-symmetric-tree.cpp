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
    bool sym(TreeNode *temp,TreeNode *ptr){
        if(temp == NULL && ptr == NULL){
            return true;
        }
        
        if(temp == NULL && ptr != NULL){
            return false;
        }
        
        if(ptr == NULL && temp != NULL){
            return false;
        }
        
        if(ptr->val != temp->val){
            return false;
        }
        
        return sym(temp->left,ptr->right) && sym(temp->right,ptr->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        
        return sym(root,root);
    }
};