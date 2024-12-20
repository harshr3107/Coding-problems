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
    TreeNode* reverseOddLevels(TreeNode* root) {
        
        
        if(root==NULL)
        {
            return root;
        }
            
        
        queue<TreeNode*> q;
        
        vector<vector<int>> ans;
        vector<int> v;
        q.push(root);
        q.push(NULL);
        
        int level=0;
        
        while(!q.empty())
        {
            
            TreeNode* temp = q.front();
            q.pop();
            
            if(temp==NULL)
            {
                //cout<<"i entered here at level"<<level<<endl;
                //cout<<"size of v is "<<v.size()<<endl;
               
                
                if((level&1)==1)
                {
                    reverse(v.begin(),v.end());
                    
                    
                }
                
                
                ans.push_back(v);
                level++;
                v.clear();
                
                if(!q.empty())
                {
                    q.push(NULL);
                    
                }
                
                
            }else{
                
                 
              
                
                if(temp->left!=NULL)
                {
                   
                    q.push(temp->left);
                }
                
                if(temp->right!=NULL)
                {
                    q.push(temp->right);
                }
                
                 
                 v.push_back(temp->val);
                
                
            }
            
        }
        
        
        TreeNode* te = new TreeNode(ans[0][0]);
        TreeNode* nroot = te;
        
        q.push(te);
        
        
        
        int child=0;
        
        
        for(int i=1;i<ans.size();i++)
        {
            for(int j=0;j<ans[i].size();j+=2)
            {  
                TreeNode* cparent = q.front();
                q.pop();
                
                TreeNode* temp1 = new TreeNode(ans[i][j]);
                TreeNode* temp2 = new TreeNode(ans[i][j+1]);
                
                cparent->left=temp1;
                cparent->right=temp2;
                
                q.push(temp1);
                q.push(temp2);
                
            }
            
       }
        
        
        
     
        
        return nroot;
        
        
        
        
        
        
        
    }
};