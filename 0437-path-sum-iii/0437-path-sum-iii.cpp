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
    
    void getpath(TreeNode* root,int targetsum,long long csum,int& cpath)
    {
        //cout<<"csum: "<<csum<<" TargetSum: "<<targetsum<<endl;
        
         if(root==NULL)
        {
            return;
        }
        
       if(static_cast<long long>(csum)+root->val==targetsum)
       {
          //cout<<"i entered here\n";
           cpath+=1;
       }
        
       
        
        
       
        
      
        //taking the node
        
       
        
        getpath(root->left,targetsum,static_cast<long long>(csum)+root->val,cpath);
        
        getpath(root->right,targetsum,static_cast<long long>(csum)+root->val,cpath);
        
     
    }
    
    
    
    
   void getallpath(TreeNode* root,int targetsum,int& ans)
    {
        
        if(root==NULL)
        {
            return;
        }
        
        int cpath=0;
        long long csum=0;
       
        getpath(root,targetsum,csum,cpath);
       
        ans+=cpath;
      // cout<<"at root ki val "<<root->val<<" the cur val of ans is "<<cpath<<endl;
        
        getallpath(root->left,targetsum,ans);
        getallpath(root->right,targetsum,ans);
        
        
    }
        
    
    
    
    
    
    
    int pathSum(TreeNode* root, int targetSum) {
        
    
        int ans=0;
        getallpath(root,targetSum,ans);
        
        return ans;
        
        
    }
};