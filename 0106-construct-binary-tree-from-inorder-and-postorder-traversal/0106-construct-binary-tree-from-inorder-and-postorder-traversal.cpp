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
    
    /*void createmap(vector<int> inorder,map<int,int>& mp)
    {
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        
        
    }*/
    int findpos(vector<int> inorder,int r)
    {
        
        int h = find(inorder.begin(),inorder.end(),r)-inorder.begin();
        
        return h;
        
    }
    
    
    TreeNode* getbinarytree(vector<int> inorder,vector<int> postorder,int& pindex,int istart,int iend)
    {
        
        if(pindex==-1 || istart>iend)
        {
            return NULL;
        }
        
        int r = postorder[pindex--];
        TreeNode* root = new TreeNode(r);
        int pos = findpos(inorder,r);
        root->right = getbinarytree(inorder,postorder,pindex,pos+1,iend);
        root->left=getbinarytree(inorder,postorder,pindex,istart,pos-1);
        
        return root;
        
        
        
        
    }
    
    
    
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int pindex=postorder.size()-1;
        int istart=0;
        int iend=inorder.size()-1;
       
        
        
        TreeNode* root = getbinarytree(inorder,postorder,pindex,istart,iend);
        
        return root;
        
    }
};