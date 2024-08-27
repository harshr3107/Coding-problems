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
    
    bool find(TreeNode* root,int x,vector<int>& v)
    {
        
        if(root==NULL)
        {
            return false;
        }
        
        v.push_back(root->val);
        
        if(root->val==x)
        {
            return true;
        }
        
       
        if(find(root->left,x,v)==true)
        {
            return true;
        }
        
        if(find(root->right,x,v)==true)
        {
            return true;
        }
        v.pop_back();
        
        return false;
        
    }
    
    
    void display(vector<int> v1)
    {
        for(int i=0;i<v1.size();i++)
        {
            cout<<v1[i]<<" ";
        }
        
        cout<<endl;
        
    }
    
    
    
    bool isCousins(TreeNode* root, int x, int y) {
        
        vector<int> v1;
        vector<int> v2;
        
        find(root,x,v1);
        find(root,y,v2);
        
        // display(v1);
         //display(v2);
        
        
        int i = v1.size()-2;
        int j= v2.size()-2;
        
        if((i>=0 && j>=0) && v1[i]==v2[j])
        {
            return false;
        }
        i--;
        j--;
        
        
        while(i>=0 && j>=0)
        {
            if(v1[i]==v2[j])
            {
                return true;
            }
            
            i--;
            j--;
        }
        
        
        
        return false;
        
        
        
    }
};