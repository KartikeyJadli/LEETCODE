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
#define LEFT 0
#define RIGHT 1
class Solution {
public:
    int max1 = 0;
    void maxZigZag(TreeNode* root, int dir, int curr){
        if(!root) return;
        
        max1=max(max1,curr);
        if(dir == LEFT){
            if(root->left){
                maxZigZag(root->left, RIGHT, curr+1);
            }

            if(root->right){
                maxZigZag(root->right, LEFT, 1);
            }
        }

        else{
            if(root->right){
                maxZigZag(root->right, LEFT, curr+1);
            }

            if(root->left){
                maxZigZag(root->left, RIGHT, 1);
            }
        }
    }

    int longestZigZag(TreeNode* root) {
        maxZigZag(root,LEFT,0);
        
        return max1;
    }
};