/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void createmapping(TreeNode* root,map<TreeNode*,TreeNode*>& mp)
    {
        
        queue<TreeNode*> q;
         mp[root]=NULL;
        
        q.push(root);
        
        
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            
            if(temp->left!=NULL)
            {
                mp[temp->left]=temp;
                q.push(temp->left);
            }
            
            if(temp->right!=NULL)
            {
                mp[temp->right]=temp;
                q.push(temp->right);
            }
            
        }
        
        
    }
    
    
    
    void getatdistance(TreeNode* root,int k,vector<int>& v,map<TreeNode*,bool>& visited,int a)
    {
        
        
        if(root==NULL)
        {
            return;
        }
        
       
        
        if(a==k && visited[root]==false)
        {
            //cout<<"value is "<<root->val<<endl;
            v.push_back(root->val);
            visited[root]=true;
            return;
        }
        
         visited[root]=true;
        
        getatdistance(root->left,k,v,visited,a+1);
        getatdistance(root->right,k,v,visited,a+1);
        
        
       
        
    }
    
    
    
    void getnodesatk(TreeNode* root,TreeNode* target,vector<int>& v,map<TreeNode*,TreeNode*> mp,int k)
    {
        
        map<TreeNode*,bool> visited;
        
        //visited[target]=true;
        
             if(k==0)
            {
                v.push_back(target->val);
            }
        
        
        while(k!=0)
        {
            //cout<<"i enter the loop for "<<target->val<<endl;
            //cout<<"value of k here is "<<k<<endl<<endl;
           
            int a=0;
            getatdistance(target,k,v,visited,a);
            visited[target]=true;
            
            target=mp[target];
            if(target==NULL)
            {
                break;
            }
            
            k=k-1;
            if(k==0)
            {
                v.push_back(target->val);
            }
            
            
            
        }
        
        
        
        
    }
    
    
    
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        map<TreeNode*,TreeNode*> mp;
        createmapping(root,mp);
        
        
       vector<int> v;
        
        getnodesatk(root,target,v,mp,k);
        
        
        return v;
    }
};