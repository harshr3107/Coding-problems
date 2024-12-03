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
    
    
    void getpath(TreeNode* root,int targetsum,vector<int>& v,vector<vector<int>>& ans)
    {
        
        if(root==NULL)
        {
            return;
        }
        
        if(root->left==NULL && root->right==NULL)
        {
            if(targetsum-root->val==0)
            {
                v.push_back(root->val);
                ans.push_back(v);
                v.pop_back();
            }
            
            return;
        }
        
        
        v.push_back(root->val);
        getpath(root->left,targetsum-root->val,v,ans);
        getpath(root->right,targetsum-root->val,v,ans);
        v.pop_back();
        
        
        
        
        
        
        
    }
    
    
    
    
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<int> v;
        vector<vector<int>> ans;
        
        
        getpath(root,targetSum,v,ans);
        
        return ans;
        
        
    }
};