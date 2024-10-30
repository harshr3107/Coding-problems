/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool getnode(TreeNode* cloned,TreeNode* target ,TreeNode*& ans)
    {
        
        if(cloned==NULL)
        {
            return false;
        }
        
        if(cloned->val==target->val)
        {
            ans=cloned;
            return true;
        }
        
        
       if(getnode(cloned->left,target,ans)==true)
       {
           
           return true;
       }
        
        if(getnode(cloned->right,target,ans)==true)
        {
            return true;
        }
        
        return false;
        
    }
    
    
    
    
    
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        
       TreeNode* ans = NULL; 
        
       getnode(cloned,target,ans);
        
        return ans;
        
    }
};