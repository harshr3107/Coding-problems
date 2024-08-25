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
    
    
    string givestring(vector<int> v)
    {
        string s=to_string(v[0]);
        
        for(int i=1;i<v.size();i++)
        {
            s=s+"->"+to_string(v[i]);
            
        }
        
        cout<<"the path is "<<s<<endl;
        
        return s;
        
    }
    
    
    
    void getallpaths (TreeNode* root,vector<int>& v,vector<string>& ans)
    {
        
        if(root==NULL)
        {
            return;
        }
        
        if(root->left==NULL && root->right==NULL)
        {
            v.push_back(root->val);
            string h = givestring(v);
            v.pop_back();
            ans.push_back(h);
            return;
        }
        
        v.push_back(root->val);
        getallpaths(root->left,v,ans);
        getallpaths(root->right,v,ans);
        v.pop_back();
        
        return;
        
        
        
        
    }
    
    
    
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string> ans;
        vector<int> v;
        
        getallpaths(root,v,ans);
        
        
        return ans;
        
        
        
    }
};