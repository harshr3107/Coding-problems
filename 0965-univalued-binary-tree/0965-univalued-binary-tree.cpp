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
    
    
    bool isuni(TreeNode* root,int data)
    {
        if(root==NULL)
        {
            return true;
        }
        
        if(root->val!=data)
        {
            return false;
        }
        
        if(isuni(root->left,data)==false)
        {
            return false;
            
        }
        
        if(isuni(root->right,data)==false)
        {
            return false;
        }
        
       
        
        
        return true;
        
        
        
    }
    
    
    
    
    bool isUnivalTree(TreeNode* root) {
       
        if(root==NULL)
        {
            return true;
        }
        
        int data= root->val;
        
        if(isuni(root,data))
        {
            return true;
        }
        
        return false;
            
       
        
    }
};