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
    
    
    
    int getans(TreeNode* root,int& ans)
    {
       // cout<<"current val of ans is "<<ans<<endl;
        
        if(root==NULL)
        {
            return 0;
        }
        
        if(root->left==NULL && root->right==NULL)
        {
            return root->val;
        }
        
        int left = getans(root->left,ans);
        int right = getans(root->right,ans);
        
        ans+=abs(left-right);
        
        if(root->left==NULL)
        {
        return root->val+right;
        }else if(root->right==NULL)
        {
             return root->val+left;
        }
        
        
         return root->val+left+right;
        
        
    }
    
    
    
    int findTilt(TreeNode* root) {
        
        int ans=0;
        getans(root,ans);
        
        return ans;
        
    }
};