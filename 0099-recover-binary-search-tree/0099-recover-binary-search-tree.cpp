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
    
    
    void inorder(TreeNode* root,vector<TreeNode*>& v)
    {
        
        if(root!=NULL)
        {
            inorder(root->left,v);
            v.push_back(root);
            inorder(root->right,v);
        }
        
    }
    
    
    
    static bool comp(TreeNode* root1,TreeNode* root2)
    {
        return root1->val<root2->val;
    }
    
    
    
    void recoverTree(TreeNode* root) {
        
       vector<TreeNode*>  v;
        inorder(root,v);
        
        int a=0;
        TreeNode* h;
        
        vector<TreeNode*> v2(v);
        sort(v2.begin(),v2.end(),comp);
        
        
        for(int i=0;i<v.size();i++)
        {
            if(v[i]!=v2[i])
            {
                a++;
                if(a==1)
                {
                    h=v[i];
                }else{
                    
                    int temp = h->val;
                    h->val=v[i]->val;
                    v[i]->val=temp;
                }
                //cout<<"i am at "<<v[i]->val<<endl;
            }
          
        }
       
       // cout<<endl;
        
        
        
        
        
        
    }
};