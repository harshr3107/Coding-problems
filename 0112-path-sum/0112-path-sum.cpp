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
    
    bool haspath(TreeNode* root,int targetsum)
    {
        if(root==NULL)
        {
            return false;
        }
        
        if(root->left==NULL && root->right==NULL)
        {
            if(targetsum-root->val==0)
            {
                return true;
            }
            
            
            return false;

        }
        
        
        if(haspath(root->left,targetsum-root->val)==true)
        {
            return true;
        }
        
        
        if(haspath(root->right,targetsum-root->val)==true)
        {
            return true;
        }
        
        return false;
        
        
        
    }
    
    
    
    bool hasPathSum(TreeNode* root, int targetsum) {
        
       return  haspath(root,targetsum);
        
    }
};