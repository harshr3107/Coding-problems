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
    
     void levelorder(TreeNode* root,vector<TreeNode*>& v)
    {
        if(root==NULL)
        {
            return;
        }
        
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
       vector<TreeNode*> vec;
        
        
        
        while(!q.empty())
        {
            
            TreeNode* temp = q.front();
            q.pop();
            
            if(temp==NULL)
            {
                v=vec;
                
                vec.clear();
                
                if(!q.empty())
                {
                    q.push(NULL);
                }
                
                
                
                
            }else{
                
                
                vec.push_back(temp);
                
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
        
    }
    
    
    bool getpath(TreeNode* root,TreeNode* reqroot,vector<TreeNode*>& v)
    {
        
        if(root==NULL)
        {
            return false;
        }
        
        if(root->val==reqroot->val)
        {
            return true;
        }
        
        v.push_back(root);
        
        if(getpath(root->left,reqroot,v)==true)
        {
            return true;
        }
        
        if(getpath(root->right,reqroot,v)==true)
        {
            return true;
        }
        
        v.pop_back();
        
        return false;
        
        
        
    }
    
    
  TreeNode* getlca(vector<TreeNode*> v1,vector<TreeNode*> v2)
    {
        set<TreeNode*> s1;
      
        for(int i=v1.size()-1;i>=0;i--)
        {
            s1.insert(v1[i]);
        }
      
        for(int i=v2.size()-1;i>=0;i--)
        {
            if(s1.count(v2[i]))
            {
                return v2[i];
            }
        }
        
        return NULL;
        
    }
    
    
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        
        
         vector<TreeNode*> v;
        
        levelorder(root,v);
        
       if(v.size()==1)
       {
           return v[0];
       }
        
        TreeNode* n1 = v[0];
        TreeNode* n2 = v[v.size()-1];
        
        vector<TreeNode*> v1;
        vector<TreeNode*> v2;
        
        
        getpath(root,n1,v1);
        getpath(root,n2,v2);
        
        
       TreeNode* ans=  getlca(v1,v2);
       
        
        
        return ans;
        
    }
        
    
};


/*

class Solution {
public:
    
    void levelorder(TreeNode* root,vector<TreeNode*>& v)
    {
        if(root==NULL)
        {
            return;
        }
        
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
       vector<TreeNode*> vec;
        
        
        
        while(!q.empty())
        {
            
            TreeNode* temp = q.front();
            q.pop();
            
            if(temp==NULL)
            {
                v=vec;
                
                vec.clear();
                
                if(!q.empty())
                {
                    q.push(NULL);
                }
                
                
                
                
            }else{
                
                
                vec.push_back(temp);
                
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
        
    }
    
    
    bool getpath(TreeNode* root,TreeNode* reqroot,vector<TreeNode*>& v)
    {
        
        if(root==NULL)
        {
            return false;
        }
        
        if(root->val==reqroot->val)
        {
            return true;
        }
        
        v.push_back(root);
        
        if(getpath(root->left,reqroot,v)==true)
        {
            return true;
        }
        
        if(getpath(root->right,reqroot,v)==true)
        {
            return true;
        }
        
        v.pop_back();
        
        return false;
        
        
        
    }
    
    
  TreeNode* getlca(vector<TreeNode*> v1,vector<TreeNode*> v2)
    {
        set<TreeNode*> s1;
      
        for(int i=v1.size()-1;i>=0;i--)
        {
            s1.insert(v1[i]);
        }
      
        for(int i=v2.size()-1;i>=0;i--)
        {
            if(s1.count(v2[i]))
            {
                return v2[i];
            }
        }
        
        return NULL;
        
    }
    
    
    
    
    
    
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        
        
        vector<TreeNode*> v;
        
        levelorder(root,v);
        
       if(v.size()==1)
       {
           return v[0];
       }
        
        TreeNode* n1 = v[0];
        TreeNode* n2 = v[v.size()-1];
        
        vector<TreeNode*> v1;
        vector<TreeNode*> v2;
        
        
        getpath(root,n1,v1);
        getpath(root,n2,v2);
        
        
       TreeNode* ans=  getlca(v1,v2);
       
        
        
        return ans;
        
    }
};

*/