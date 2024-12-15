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
    
    
    int getmaxi(TreeNode* root,int& ans)
    {
        
        if(root==NULL)
        {
            return 0;
        }
        
        
        if(root->left==NULL && root->right==NULL)
        {
            ans = max(ans,root->val);
            return root->val;
        }
        
        
        int left = getmaxi(root->left,ans);
        int right = getmaxi(root->right,ans);
        
        cout<<left<<" "<<right<<" "<<root->val<<endl;
       
        
        int maxi = max(max(root->val+left,root->val+right),root->val);
        
        cout<<"current val of maxi is "<<maxi<<endl;
        
        ans = max(ans,max(maxi,left+right+root->val));
        
       
        
        return maxi;
        
        
        
       
        
        
        
        
        
        
    }
    
    
    
    int maxPathSum(TreeNode* root) {
        
        int ans=INT_MIN;
        
         getmaxi(root,ans);
        
        return ans;
        
        
        
    }
};