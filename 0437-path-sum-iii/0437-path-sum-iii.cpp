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
    
    void getcount(TreeNode* root,int targetsum,vector<int>& num,int& count)
    {
        if(root==NULL)
        {
            return;
        }
        
        num.push_back(root->val);
        
        
        
        getcount(root->left,targetsum,num,count);
        getcount(root->right,targetsum,num,count);
        
        long long sum=0;
        
        for(int i=num.size()-1;i>=0;i--)
        {
            sum+=num[i];
            
            
            
            if(sum==targetsum)
            {
                count++;
                
            }
        }
        
        num.pop_back();
        
    }
    
    
    
    
    
    int pathSum(TreeNode* root, int targetsum) {
        
        int count=0;
        vector<int> num;
        
        getcount(root,targetsum,num,count);
        
        
        return count;
        
    }
};