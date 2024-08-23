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
    
    
int findnode(TreeNode* root,TreeNode* key,vector<TreeNode*>& a)
{
    
    if(root==NULL)
    {
        if(!a.empty())
        {
        a.pop_back();
        }
        return 0;
        
    }
       
       
    
    if(root==key)
    {
        a.push_back(root);
        return -1;
    }
    
    if(root->left==NULL && root->right==NULL)
    {
        a.pop_back();
        return 0;
    }
       
     
     cout<<"i entered here for "<<root->val<<endl;
     a.push_back(root);
   
     if(findnode(root->left,key,a)==-1)
     {
        
         return -1;
     }
    
        
   
    
     a.push_back(root);
    
    if(findnode(root->right,key,a)==-1)
    {
       
        return -1;
    }
    
    a.pop_back();

    
    return 0;
    
}
    
    
    void display(vector<TreeNode*> v)
    {
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]->val<<" ";
        }
        
        cout<<endl;
    }




 
    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        vector<TreeNode*> ancestor1;
        vector<TreeNode*> ancestor2;
        
        findnode(root,p,ancestor1);
        findnode(root,q,ancestor2);
        
        //display(ancestor1);
        //display(ancestor2);
        
        int j=ancestor1.size()-1;
        
        while(j>0)
        {
            if(find(ancestor2.begin(),ancestor2.end(),ancestor1[j])!=ancestor2.end())
            {
               return ancestor1[j];   
            }
            
            j--;
                
            
        }
        
        
        
        
        return root;
        
    }
};