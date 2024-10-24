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
    
    void getallvalues(TreeNode* root,map<int,set<int>>& mp)
    {
        
       
        if(root==NULL)
        {
            return;
        }
        
        if(root->left!=NULL)
        {
            mp[root->val].insert(root->left->val);
            
        }
        
        if(root->right!=NULL)
        {
            mp[root->val].insert(root->right->val);
        }
        
        mp[root->val].insert(-1);
            
            
        getallvalues(root->left,mp);
        getallvalues(root->right,mp);
        
        
        
    }
    
    
    
    
    
    
    
    
    
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        
    
         map<int,set<int>> mp1;
        map<int,set<int>> mp2;
        
        getallvalues(root1,mp1);
        getallvalues(root2,mp2);
        
        
        if(mp1.size()!=mp2.size())
        {
            return false;
        }
        
       // cout<<"the size of the map is "<<mp1.size()<<endl;
        
       /* for(auto it : mp1)
        {
            cout<<it.first<<"->";
            for(auto it2 : it.second)
            {
                cout<<it2<<" ";
            }
            cout<<endl;
        }
        
        cout<<endl<<endl;
        
         for(auto it : mp2)
        {
            cout<<it.first<<"->";
            for(auto it2 : it.second)
            {
                cout<<it2<<" ";
            }
            cout<<endl;
        }*/
        
        
        if(mp1==mp2)
        {
            return true;
        }

    
        return false;
        
        
    }
};