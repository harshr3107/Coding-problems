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
    
    void getgood(TreeNode* root,int& ans,int max)
    {
        if(root==NULL)
        {
            return;
        }
        
        if(root->val>=max)
        {
            //cout<<"i entered here for "<<root->val<<endl;
            ans=ans+1;
            max=root->val;
        }
        
        getgood(root->left,ans,max);
        getgood(root->right,ans,max);
        
    }
    
    
    
    
    
    int goodNodes(TreeNode* root) {
        
        int ans=0;
        int max=INT_MIN;
        getgood(root,ans,max);
        
        return ans;
        
        
    }
};