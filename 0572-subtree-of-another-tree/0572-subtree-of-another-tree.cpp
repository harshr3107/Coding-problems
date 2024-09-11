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
    
    bool checkifsame(TreeNode* root,TreeNode* root2)
    {
        if(root==NULL && root2==NULL)
        {
            return true;
        }
        
        if(root==NULL || root2==NULL)
        {
            return false;
        }
        
        if(root->val!=root2->val)
        {
            return false;
        }
        
        if(checkifsame(root->left,root2->left)==false)
        {
            return false;
        }
        if(checkifsame(root->right,root2->right)==false)
        {
            return false;
        }
        
        return true;
        
        
    }
    
    
    
    
    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        
        if(root==NULL && subroot==NULL)
        {
            return true;
        }else if(root==NULL)
        {
            return false;
        }
        
        if(root->val==subroot->val)
        {
              if(checkifsame(root,subroot)==true)
              {
                  return true;
              }
            
        }
        
        
        
        return isSubtree(root->left,subroot) || isSubtree(root->right,subroot);
        
        
        
        
    }
};