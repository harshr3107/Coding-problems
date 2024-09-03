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
    bool isEvenOddTree(TreeNode* root) {
      
        if(root==NULL)
        {
            return root;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int a=0;
        
        vector<int> v;
        
    
       
        
        
        while(!q.empty())
        {
            
            TreeNode* temp=q.front();
            q.pop();
            
            
            if(temp==NULL)
            {
                //cout<<"i entered here for level "<<a<<endl;
                
                
                if(a%2==0)
                {
                    //cout<<"yaha pe aaya mai\n";
                    if(v.size()==1)
                    {
                        if(v[0]%2==0)
                        {
                            return false;
                        }
                        
                        
                        
                    }else{
                        
                         if(v[0]%2==0)
                        {
                            return false;
                        }
                        
                        for(int i=1;i<v.size();i++)
                        {
                            if(v[i]%2==0 || v[i]<=v[i-1])
                            {
                                return false;
                            }
                        }
                        
                        
                        
                    }
                    
                    
                    
                    
                }else{
                    
                    if(v.size()==1)
                    {
                        
                        
                       if(v[0]%2==1)
                        {
                          return false;
                        }
                        
                        
                    }else{
                        
                       // cout<<"mai yha pe aaya bro\n";
                        //cout<<"value of v[0] is "<<v[0]<<endl;
                        
                        if(v[0]%2==1)
                        {
                            return false;
                        }
                        
                         for(int i=1;i<v.size();i++)
                        {
                            if(v[i]%2==1 || v[i]>=v[i-1])
                            {
                                return false;
                            }
                        }
                        
                    }
                    
                    
                }
                
                
                
                    
            a++;
                
                v.clear();
                
                if(!q.empty())
                {
                    q.push(NULL);
                }
                
               
                
            }else{
               
                v.push_back(temp->val);
                
                if(temp->left!=NULL)
                {
                    q.push(temp->left);
                }
                if(temp->right!=NULL)
                {
                    q.push(temp->right);
                }
                
                
            }
            
            
            
            
            
        }
            
        
        
        
       return true; 
        
    }
};
            