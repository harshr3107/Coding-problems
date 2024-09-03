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
    
    void getans(TreeNode* root,int& ans)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->left==NULL && root->right==NULL)
        {
            return;
        }
        
        getans(root->left,ans);
        getans(root->right,ans);
        
        if(root->val%2==0)
        {
            //cout<<"i am at root "<<root->val<<endl;
            
            if(root->left!=NULL && root->left->left!=NULL)
            {
                ans+=root->left->left->val;
                
            }
            
             if(root->left!=NULL && root->left->right!=NULL)
            {
                ans+=root->left->right->val;
                
            }
            
             if(root->right!=NULL && root->right->right!=NULL)
            {
                ans+=root->right->right->val;
            }
             if(root->right!=NULL && root->right->left!=NULL)
            {
                ans+=root->right->left->val;
            }
            
            //cout<<"current value of ans is "<<ans<<endl;
            
            
        }
        
        
        
    }
    
    
    
    int sumEvenGrandparent(TreeNode* root) {
        
       int ans=0;
        
       getans(root,ans);
        
        
        return ans;
        
        
    }
};