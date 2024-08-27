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
    
    TreeNode* makebst(vector<int> v,int istart,int iend)
    {
        if(istart>iend)
        {
            return NULL;
        }
        
        int mid = (istart+iend)/2;
        TreeNode* root = new TreeNode(v[mid]);
        
        root->left = makebst(v,istart,mid-1);
        root->right = makebst(v,mid+1,iend);
        
        
        return root;
        
        
    }
    
    
    
    TreeNode* balanceBST(TreeNode* root) {
        
        vector<int> v;
        inorder(root,v);
        
        TreeNode* r = makebst(v,0,v.size()-1);
        
        return r;
    }
};