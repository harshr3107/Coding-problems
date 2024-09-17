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
    
    
    
    
    
    
    vector<int> findMode(TreeNode* root) {
        
        
        
        vector<int> v;
        inorder(root,v);
       
        
        vector<int> ans;
       
        int a=1;
        int max_size = 1;
        //ans.push_back(v[0]);
        
        for(int i=0;i<v.size()-1;i++)
        {
            if(v[i]==v[i+1])
            {
                a++;
                if(a==max_size)
                {
                    ans.push_back(v[i]);
                    
                }else if(a>max_size)
                {
                    ans.clear();
                    ans.push_back(v[i]);   
                    max_size=a;
                    
                }
                
            }else{
                a=1;
            }
            
        }
        
        cout<<"max_sie is "<<max_size<<endl;
        
        if(max_size==1)
        {
            return v;
        }
        
        
        
        
        
        return ans;
        
    }
};