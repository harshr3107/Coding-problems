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
    
    void getinorder(TreeNode* root,TreeNode*& newroot)
    {
        if(root!=NULL)
        {
            getinorder(root->left,newroot);
            //cout<<"i enteed here for "<<root->val<<endl;
            newroot->right = new TreeNode(root->val);
            newroot=newroot->right;
            getinorder(root->right,newroot);
            
        }
        
    }
    
    
    
    
    TreeNode* increasingBST(TreeNode* root) {
        
        
        
        TreeNode* dummy = new TreeNode(-1);
       
         TreeNode* newroot=dummy;
        
        getinorder(root,newroot);
        
        return dummy->right;
        
    }
};