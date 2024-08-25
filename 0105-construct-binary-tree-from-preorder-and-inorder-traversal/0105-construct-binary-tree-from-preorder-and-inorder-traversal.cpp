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
    
    
    int findpos(vector<int> inorder,int r)
    {
        
        int h = find(inorder.begin(),inorder.end(),r)-inorder.begin();
        
        return h;
        
    }
    
    
    
    
    TreeNode* getbinarytree(vector<int> preorder,vector<int> inorder,int& pindex,int istart,int iend)
    {
        if(pindex==preorder.size() || istart>iend)
        {
            return NULL;
        }
        
        int r = preorder[pindex++];
        TreeNode* root = new TreeNode(r);
        int pos = findpos(inorder,r);
        
        root->left=getbinarytree(preorder,inorder,pindex,istart,pos-1);
        root->right=getbinarytree(preorder,inorder,pindex,pos+1,iend);
        
    
        return root;
        
        
        
    }
    
    
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int pindex=0;
        int istart=0;
        int iend=inorder.size()-1;
        
        TreeNode* root = getbinarytree(preorder,inorder,pindex,istart,iend);
        
        
        return root;
        
    }
};