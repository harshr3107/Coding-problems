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
    
    void inorder(TreeNode* root,vector<int>& v)
    {
        
        if(root!=NULL)
        {
            
            inorder(root->left,v);
            v.push_back(root->val);
            inorder(root->right,v);
            
        }    
            
        
    }
    
    
    void convert(TreeNode* root,vector<int>& postfix)
    {
        if(root!=NULL)
        {
            convert(root->left,postfix);
            root->val=postfix[postfix.size()-1];
            postfix.pop_back();
            convert(root->right,postfix);
            
        }
        
    }
    
    
    
    
    TreeNode* convertBST(TreeNode* root) {
        
        if(root==NULL)
        {
            return root;
        }
        
        
        vector<int> v;
        inorder(root,v);
        
        vector<int> postfix(v.size());
        
        postfix[v.size()-1]=v[v.size()-1];
        
        int sum=v[v.size()-1];
        
        for(int j=v.size()-2;j>=0;j--)
        {
            sum+=v[j];
            postfix[j]=sum;
        }
        
        reverse(postfix.begin(),postfix.end());
        
        convert(root,postfix);
        
        return root;
        
        
    }
};