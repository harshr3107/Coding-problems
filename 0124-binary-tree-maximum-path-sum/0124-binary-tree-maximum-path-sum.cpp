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
    
    int findpathsum(TreeNode* root,int& maxi)
    {
        
        if(root==NULL)
        {
            return NULL;
        }
        
        if(root->left==NULL && root->right==NULL)
        {
            maxi=max(maxi,root->val);
            return root->val;
        }
        
        int left = findpathsum(root->left,maxi);
        int right = findpathsum(root->right,maxi);
        maxi = max(maxi,max(left+right+root->val,root->val));
        
        maxi = max(maxi,max(left+root->val,right+root->val));
        //cout<<"current value of maxi is "<<maxi<<endl;
        
        return max(root->val+left,max(root->val+right,root->val));
        
        
    }
    
    
    
    
    int maxPathSum(TreeNode* root) {
        
        if(root==NULL)
        {
            return 0;
        }
        
        
        int maxi=INT_MIN;
        findpathsum(root,maxi);
        
        
        return maxi;
        
        
        
    }
};