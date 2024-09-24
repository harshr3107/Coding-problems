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
    int sumOfLeftLeaves(TreeNode* root) {
        
       // cout<<"i entered here for "<<root->val<<endl;
        
        if(root==NULL)
        {
            return 0;
        }
        
        
      //cout<<"i entered here for "<<root->val<<endl;
        
        
        int left = sumOfLeftLeaves(root->left);
        int right = sumOfLeftLeaves(root->right);
        
        
        if(root->left!=NULL && root->left->left==NULL && root->left->right==NULL)
        {
            
                 return left+right+root->left->val;
        }
        
        
        
        return left+right;
        
        
    }
};