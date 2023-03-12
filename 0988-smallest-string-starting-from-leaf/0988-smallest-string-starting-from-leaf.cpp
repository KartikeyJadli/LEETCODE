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
    string smallestFromLeaf(TreeNode* root) {
        string str = "", best = "";
        getNext(root, &str, &best);
        return best;
    }
    
    void getNext(TreeNode* node, string *str, string *best) {
        if (node != NULL) {
            string nextString = (char)(node->val+97) + *str;

            if (node->left == NULL && node->right == NULL) {
                if (*best == "" || nextString < *best) {
                    *best = nextString;
                }    
            } 
            
            else{
                getNext(node->left, &nextString, best);
                getNext(node->right, &nextString, best);
            }
        }
    }
};