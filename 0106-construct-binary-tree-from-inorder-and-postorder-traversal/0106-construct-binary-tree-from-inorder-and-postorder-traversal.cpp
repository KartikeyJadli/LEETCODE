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
//     int search(vector<int> &inorder,int i,int j,int val){
//         for(int x=i;x<j;x++){
//             if(inorder[x] == val){
//                 return i;
//             }
//         }
        
//         return -1;
//     }
    
//     TreeNode* createtree(vector<int> &inorder,vector<int> &postorder,int i,int j){
//         int idx = j;
//         int temp = postorder[idx];
//         idx--;
        
//         if(i > j){
//             return NULL;
//         }
        
//         TreeNode *root = new TreeNode(temp);

//         if(i == j){
//             return root;
//         }
        
//         int pos = search(inorder,i,j,temp);
//         root->right = createtree(inorder,postorder,pos+1,j);
//         root->left = createtree(inorder,postorder,i,pos-1);
        
//         return root;
        
//     }
    
    TreeNode* createtree(int &i,vector<int> &in,vector<int> &post,int l,int r){
        if(l > r)
            return NULL;
        
        int x = r;
        while(post[i] != in[x]){
            x--;
        }
        
        i--;
        
        TreeNode* root = new TreeNode(in[x]);
        root->right = createtree(i,in,post,x+1,r);
        root->left = createtree(i,in,post,l,x-1);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//         int n = inorder.size() - 1;
//         TreeNode *root = createtree(inorder,postorder,0,n);
        
//         return root;
        
        int i1 = postorder.size()-1;
        return createtree(i1,inorder,postorder,0,inorder.size()-1);
    }
};