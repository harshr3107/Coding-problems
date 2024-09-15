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
/*
class Solution {
public:
    
    
    
    
    
    
    
    
    
    
    
    
    void getbst(TreeNode*& root,int low,int high)
    {
        
        
        if(root==NULL)
        {
            return;
        }   
        
        if(root->left!=NULL)
        {
            if(root->val>high)
            {
                root=root->left->left;
            }else if(root->val<low)
            {
                root=root->left->right;
            }
            
            
        }
        
        if(root->right!=NULL)
        {
            if(root->val>high)
            {
                root=root->right->left;
            }else if(root->val<low)
            {
                root=root->right->right;
            }
            
            
        }
        
        
        
        getbst(root->left,low,high);
        getbst(root->right,low,high);
        
            
        
        
        
        
    }
    
    
    
    
    
    
    
    
    
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        
        getbst(root,low,high); 
        
        return root;
        
    }
};
*/


class Solution {
public:
    void Trim(TreeNode* root, int low, int high){
        if(root==NULL) return;
        while(root->left != NULL){
            if(root->left->val < low) root->left = root->left->right;
            else if(root->left->val > high) root->left = root->left->left;
            else break;
        }
         while(root->right != NULL){
            if(root->right->val > high) root->right = root->right->left;
            else if(root->right->val < low) root->right = root->right->right;
            else break;
        }
        // root = [1,0,2] -> dry run to understand why we need recursion
        Trim(root->left,low,high);
        Trim(root->right,low,high);
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        TreeNode*dummy=new TreeNode(INT_MAX);
        dummy->left=root;
        Trim(dummy,low,high);
        return dummy->left;
    }
};
