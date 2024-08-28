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
    
    
    void getrootnodes(TreeNode* root,vector<int>& v)
    {
        if(root==NULL)
        {
            return;
        }
        
        if(root->left==NULL && root->right==NULL)
        {
            v.push_back(root->val);
        
        }
        
        getrootnodes(root->left,v);
        getrootnodes(root->right,v);
        
        
    }
    
   /* void display(vector<int> v)
    {
        
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
        
        cout<<endl;
    }
    */
    
    
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
       vector<int> root1n;
       vector<int> root2n;
        
        getrootnodes(root1,root1n);
        getrootnodes(root2,root2n);
        
        //display(root1n);
        
        
        if(root1n.size()!=root2n.size())
        {
            return false;
        }
        
        for(int i=0;i<root1n.size();i++)
        {
            if(root1n[i]!=root2n[i])
            {
                return false;
            }
        }
        
        
        return true;
    }
};