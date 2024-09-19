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
    
    
    int getzigzagpath(TreeNode* root)
    {
        //cout<<"i entered here for "<<root->val<<endl;
        
        int leftans=0;
        int rightans=0;
        int flag=0;
        
        TreeNode* temp = root;
        
        while(temp!=NULL)
        {
            
            if(flag%2==0)
            {
                temp=temp->left;
            }else{
                temp=temp->right;
            }
            
            flag++;
            
            
        }
        
        //cout<<"val of left flag here is "<<flag-1<<endl;
        
        leftans=flag-1;
        
        flag=0;
        
        while(root!=NULL)
        {
            
            if(flag%2==0)
            {
               
                root=root->right;
                
            }else{
                root=root->left;
            }
            
            flag++;
           
            
            
        }
        // cout<<"val of right flag here is "<<flag-1<<endl;
        rightans=flag-1;
        
        //cout<<"here ans is "<<max(leftans,rightans)-1;
        //cout<<endl<<endl;
        
        return max(leftans,rightans);
        
        
    }
    
    
    
    
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
        
       
        
        ans = max(ans,getzigzagpath(root));
        
        
        
        
        
    }
    
    
    
    int longestZigZag(TreeNode* root) {
        
        
        
        int ans=0;
        
        
        getans(root,ans);
        
        
        
        return ans;
        
        
    }
};