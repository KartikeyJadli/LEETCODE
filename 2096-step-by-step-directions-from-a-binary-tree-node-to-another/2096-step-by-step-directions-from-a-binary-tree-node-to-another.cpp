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
    TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) {
        if(root == NULL){
            return NULL;
        }    

        if(root->val == p || root->val == q){
            return root;
        }

        TreeNode *left=lowestCommonAncestor(root->left,p,q);
        TreeNode *right=lowestCommonAncestor(root->right,p,q);
          
        if(left != NULL && right != NULL){
            return root;
        }

        else{
            if(left == NULL){
                return right;
            }

            else{
                return left;
            }
        }

        return NULL;
    }
    
    bool find_path(TreeNode* root,string &ans,int target){
        if(root==NULL){
            return 0;
        }

        if(root->val==target){
            return 1;
        }

        bool left=find_path(root->left,ans,target);
        if(left){
            ans += 'L';
        }

        bool right=find_path(root->right,ans,target);
        if(right){
            ans += 'R';
        }

        return left||right;      
    }

    string getDirections(TreeNode* root, int start, int dest) { 
        TreeNode* lca = lowestCommonAncestor(root,start,dest);
        string start_lca;
        string end_lca;
        find_path(lca,start_lca,start);
        find_path(lca,end_lca,dest);
        
        for(int i=0;i<start_lca.size();i++){
            start_lca[i] = 'U';
        }

        reverse(end_lca.begin(),end_lca.end());
        return start_lca+end_lca;    
    }
};