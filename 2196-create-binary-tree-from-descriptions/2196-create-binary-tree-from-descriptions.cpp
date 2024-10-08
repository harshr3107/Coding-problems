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
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        
        unordered_map<int,TreeNode*> mp;
        unordered_set<int> s;
        
        
        for(int i=0;i<d.size();i++)
        {
            
            int u=d[i][0];
            int v=d[i][1];
            
            TreeNode* ut;
            TreeNode* vt;
            
            s.insert(v);
            
            if(mp.count(u))
            {
                //cout<<"yes their exist a node with val "<<u<<endl;
                 ut = mp[u];
            }else{
                
                //cout<<"we are forming a very new node\n";
                ut = new TreeNode(u);
                
            }
            
             if(mp.count(v))
            {
                // cout<<"yes their exist a node with val "<<v<<endl;
                 vt = mp[v];
            }else{
                
                //cout<<"we are forming a very new node\n";
                vt = new TreeNode(v);
                
            }
            
            
            if(d[i][2]==1)
            {
                ut->left=vt;
            }else{
                
                ut->right=vt;
            }
            
            mp[u]=ut;
            mp[v]=vt;
            
        }
        
        
        //Now we need to find the parent;
        
        for(auto it: mp)
        {
           // cout<<"i entered ghere for "<<it.first<<endl;
            
            if(s.count(it.first)==0)
            {
                //cout<<"i came here to return at "<<it.first<<endl;

                return mp[it.first];
            }
        }
        
        
        return NULL;
        
    }
};