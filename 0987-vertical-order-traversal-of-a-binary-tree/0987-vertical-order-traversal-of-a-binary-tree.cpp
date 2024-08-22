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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
       
        map<int,map<int,vector<int>>> m;
        
          vector<vector<int>> ans;
        
        
        if(root==NULL)
        {
            return ans;
        }
        
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push(make_pair(root,make_pair(0,0)));
        
        
        while(!q.empty())
        {
            pair<TreeNode*,pair<int,int>> temp = q.front();
            q.pop();
            
            TreeNode* node = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;
            
            m[hd][lvl].push_back(node->val);
            
            if(node->left!=NULL)
            {
                
                q.push(make_pair(node->left,make_pair(hd-1,lvl+1)));
            }
            
            if(node->right!=NULL)
            {
                q.push(make_pair(node->right,make_pair(hd+1,lvl+1)));
            }
            
        }
        
        
      vector<int> v;
        
        
       for (auto it : m) {
            vector<int> temp;
            for (auto x : it.second) {
                sort(x.second.begin(), x.second.end());
                for (int i : x.second) temp.push_back(i);
            }
            ans.push_back(temp);
        }
        
        
        return ans;
        
       

        
        
        
    }
};