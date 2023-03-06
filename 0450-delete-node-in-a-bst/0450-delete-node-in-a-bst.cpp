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
    TreeNode *inpre(TreeNode *root){
        if(root->left == NULL){
            return root;
        }
        // root = root->right;
        while(root->left != NULL){
            root = root->left;
        }

        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return NULL;
        }

        if(root->val > key){
            root->left = deleteNode(root->left,key);
        }

        else if(root->val < key){
            root->right = deleteNode(root->right,key);
        }

        // else if(root->val == key){
        //     TreeNode *ptr = inpre(root);
        //     root->val = ptr->val;
        //     root->right = deleteNode(root->right,ptr->val);
        // }

        // return root;

        else{
            if(root->left==NULL && root->right==NULL){
                return NULL;
            }
            
            if(root->left==NULL) 
                return root->right;
            
            else if(root->right==NULL) 
                return root->left;
            
            TreeNode* inSucc=inpre(root->right);
            root->val = inSucc->val;
            root->right = deleteNode(root->right,inSucc->val);
        }
        
        return root;
    }
};