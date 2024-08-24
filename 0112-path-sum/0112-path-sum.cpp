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
    
    int sum=0;
    int a=0;
    
    bool hasPathSum(TreeNode* root, int targetsum) {
        
        if(root==NULL)
        {
          
            return false;
        }
        
        if(root->left==NULL && root->right==NULL)
        {
            if(sum+root->val==targetsum)
            {
                return true;
            }
            
            return false;
        }
        
        sum+=root->val;
        a++;
        if(hasPathSum(root->left,targetsum)==true)
        {
           return true; 
        }
        if(hasPathSum(root->right,targetsum)==true)
        {
            return true;
        }
        sum-=root->val;
        
        return false;
        
    }
};