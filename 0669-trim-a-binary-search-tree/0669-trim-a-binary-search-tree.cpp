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
    

    
    
   void getnewtree(TreeNode*& root,int low,int high)
    {
        if(root==NULL)
        {
            return;
        }
         
       
         if(root->val>=low && root->val<=high)
         {
             getnewtree(root->left,low,high);
             getnewtree(root->right,low,high);
             
         }else if(root->val<=low){
             
             
            root->left=NULL;
            root=root->right;
            getnewtree(root,low,high);
             
             
             
         }else{
             
             root->right=NULL;
             root=root->left;
             getnewtree(root,low,high);
             
         }
       
       
    }
    
    
    
    
    
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        
        getnewtree(root,low,high);
        
        return root;
        
        
    }
};