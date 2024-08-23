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
    
    bool checksymetric(TreeNode* root1,TreeNode* root2)
    {
        
        if(root1==NULL && root2==NULL)
        {
            return true;
        }
        if(root1==NULL && root2!=NULL)
        {
            return false;
        }
        if(root1!=NULL && root2==NULL)
        {
            return false;
        }
        
        if(checksymetric(root1->left,root2->right)==false)
        {
            return false;
        }
        
        if(checksymetric(root1->right,root2->left)==false)
        {
            return false;
        }
        
        if(root1->val!=root2->val)
        {
            return false;
        }
        
        
        return true;
        
    }
    
    
    
    
    
    bool isSymmetric(TreeNode* root) {
        
        bool ans=true;
        
        if(root==NULL)
        {
            return ans;
        }
        
        ans = checksymetric(root->left,root->right);
        
        return ans;
        
        
        
    }
};