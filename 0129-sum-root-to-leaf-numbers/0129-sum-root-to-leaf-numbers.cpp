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
    
    
    
    
    
    void display(vector<int> nums)
    {
        for(int i=0;i<nums.size();i++)
        {
            cout<<nums[i]<<" ";
        }
        
        cout<<endl;
    }
    
    int sum=0;
    
    void getnums(TreeNode* root,vector<int>& nums)
    {
        
        if(root==NULL)
        {
            return;
        }
        
        if(root->left==NULL && root->right==NULL)
        {
            
            nums.push_back(sum*10+root->val);
            return;
        }
        
        sum=sum*10+root->val;
        getnums(root->left,nums);
        getnums(root->right,nums);
        sum=sum/10;
        
        
        
    }
    
    
    
    
    
    
    int sumNumbers(TreeNode* root) {
        
        vector<int> nums;
        
        getnums(root,nums);
        
        
        display(nums);
        
        int sum = accumulate(nums.begin(),nums.end(),0);
        
        return sum;
        
        
    }
};