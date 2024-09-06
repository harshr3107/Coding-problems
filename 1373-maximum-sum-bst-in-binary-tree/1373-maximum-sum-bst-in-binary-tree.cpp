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
    
    
    int getsumalltree(TreeNode* root,int& maxi)
    {
        
        if(root==NULL)
        {
            return 0;
        }
        
        if(root->left==NULL && root->right==NULL)
        {
            maxi=max(maxi,root->val);
            return root->val;
        }
        
        int left = getsumalltree(root->left,maxi);
        int right = getsumalltree(root->right,maxi);
        
       // maxi = max(maxi,max(left,right));
        //maxi = max(maxi,max(root->val+left,root->val+right));
        maxi= max(maxi,root->val+left+right);
      
        return root->val+left+right;
        
        
        
    }
    
    
    bool isBst(TreeNode* root,int min,int max)
    {
        
       
        
        
        if(root==NULL)
        {
            return true;
        }
         //cout<<root->val<<" "<<"the min is "<<min<<" the max is "<<max<<endl;
        
       
        
         if(root->val<=min || root->val>=max)
        {
            return false;
        }
        
       
        
        if(isBst(root->left,min,root->val)==false)
        {
           return false;  
        }
        if(isBst(root->right,root->val,max)==false)
        {
           return false;   
        }
        
       
        
        
        return true;
        
        
    }
    
    
    
    void havedepthsearch(TreeNode* root,int& maxi)
    {
        
        if(root==NULL)
        {
            return;
        }
        
           if(isBst(root,INT_MIN,INT_MAX))
        {
            //cout<<"i entered here for "<<root->val<<endl;
            int h  = getsumalltree(root,maxi);
            //maxi=max(maxi,h);
            return;
        }
       
        
        
        havedepthsearch(root->left,maxi);
        havedepthsearch(root->right,maxi);
        
      
        
        
    }
    
    
    
    int maxSumBST(TreeNode* root) {
        
        int maxi=INT_MIN;
        
        havedepthsearch(root,maxi);
        
        if(maxi<0)
        {
            return 0;
        }
        
        return maxi;
        
        
    }
};