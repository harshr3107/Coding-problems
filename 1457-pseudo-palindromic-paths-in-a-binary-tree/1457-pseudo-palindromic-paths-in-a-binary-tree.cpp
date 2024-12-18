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
    
    
    
    
    bool checkmap(unordered_map<int,int>& mp)
    {
        int a=0;
        
        for(auto it: mp)
        {
            //cout<<it.first<<" "<<it.second<<endl;
            
            if(((it.second)&1)==1)
            {
                a++;
            }
            
        }
        
        
       // cout<<endl<<endl;
        
       if(a>1)
       {
           return false;
       }

        
        
        return true;
        
    }
    
    
    int getpath(TreeNode* root,unordered_map<int,int>& mp)
    {
        if(root==NULL)
        {
            
            return 0;
        }
        
        
        if(root->left==NULL && root->right==NULL)
        {
            int a=0;
            mp[root->val]++;
            if(checkmap(mp))
            {
                a=1;
            }
            mp[root->val]--;
            
            return a;
            
        }
        
        
        mp[root->val]++;
        int left = getpath(root->left,mp);
        int right = getpath(root->right,mp);
        mp[root->val]--;
        
        return left+right;
        
        
    }
    
    
    
    
    
    
    int pseudoPalindromicPaths (TreeNode* root) {
        
        unordered_map<int,int> mp;
        
         return getpath(root,mp);
        
    }
};