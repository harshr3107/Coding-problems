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
    
    void getmini(TreeNode* root,int& mini,int a)
    {
        
        if(root==NULL)
        {
            return;
        }
        
        if(root->left==NULL && root->right==NULL)
        {
            a=a+1;
            mini = min(mini,a);
            return;
        }
        
        
        a=a+1;
        getmini(root->left,mini,a);
        getmini(root->right,mini,a);
        
        
        
        
    }
    
    
    
    int minDepth(TreeNode* root) {
        
        
        if(root==NULL)
        {
            return 0;
        }
        
        
        int a=0;
        
    
        
        int mini =INT_MAX;
        getmini(root,mini,a);
        
       
        
        return mini;
        
    }
};