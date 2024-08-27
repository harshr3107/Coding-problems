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
    
    
    int greaterthanr(vector<int>& preorder,int start,int end,int r)
    {
        for(int i=start;i<=end;i++)
        {
            if(preorder[i]>r)
            {
                //cout<<"i am returning "<<preorder[i]<<endl;
                return i;
            }
        }
        
        return -1;
        
    }
    
    
    
    TreeNode* getbst(vector<int> preorder,int& pind,int start,int end)
    {
        if(start>end || start<0 || end<0)
        {
            return NULL;
        }
        
        int r = preorder[pind++];
        int pos = greaterthanr(preorder,start,end,r);
        if(pos==-1)
        {
            pos=end+1;
        }
        
        TreeNode* root = new TreeNode(r);
        
        root->left = getbst(preorder,pind,pind,pos-1);
        root->right=getbst(preorder,pind,pos,end);
        
        return root;
        
        
    }
    
    
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int pind=0;
        int start=0;
        int end=preorder.size()-1;
        
        TreeNode* root = getbst(preorder,pind,start,end);
        
        
        
        return root;
        
        
        
    }
};