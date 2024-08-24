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
    
    void findallpath(TreeNode* root,int targetsum,int& sum,vector<int>& v,vector<vector<int>>& ans)
    {
        
        if(root==NULL)
        {
            return;
        }
        
        if(root->left==NULL && root->right==NULL)
        {
            if(sum+root->val==targetsum)
            {
                v.push_back(root->val);
                ans.push_back(v);
                v.pop_back();
            }
            
            return;
        }
        
        
        sum=sum+root->val;
        v.push_back(root->val);
        
        findallpath(root->left,targetsum,sum,v,ans);
        findallpath(root->right,targetsum,sum,v,ans);
        
        sum=sum-root->val;
        v.pop_back();
        
        
        
        
        
    }
    
    
    
    
    
    vector<vector<int>> pathSum(TreeNode* root, int targetsum) {
        
        vector<vector<int>> ans;
        vector<int> v;
        int sum=0;
        
        findallpath(root,targetsum,sum,v,ans);
        
        
        return ans;
        
    }
};