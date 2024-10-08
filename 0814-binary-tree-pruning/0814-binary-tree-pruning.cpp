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
    
    void prune(TreeNode*& root)
    {
        
        if(root==NULL)
        {
            return;
        }
        
        if(root->left==NULL && root->right==NULL)
        {
            if(root->val!=1)
            {
                root=root->left;
            }
            return;
        }
        
        
        prune(root->left);
        prune(root->right);
        
        if(root->left==NULL && root->right==NULL && root->val!=1)
        {
            root=root->left;
        }

            
        
        
        
    }
    
    
    
    
    
    TreeNode* pruneTree(TreeNode* root) {
        
        
        prune(root);
        
        return root;
        
        
        
    }
};