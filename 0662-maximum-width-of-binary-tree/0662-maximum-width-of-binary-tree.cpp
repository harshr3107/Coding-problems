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
    
    
    void display(vector<pair<int,int>> v)
    {
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i].first<<" ";
        }
        cout<<endl;
       
    }
    
    
    int widthOfBinaryTree(TreeNode* root) {
        
        queue<pair<TreeNode*,int>> q;
        
        TreeNode* z = NULL;
        
        q.push(make_pair(root,0));
        q.push(make_pair(z,-112));
        
        vector<pair<int,int>> v;
        
        int maxi=INT_MIN;
        
        while(!q.empty())
        {
            pair<TreeNode*,int> temp = q.front();
            q.pop();
            
            TreeNode* p = temp.first;
            int hd = temp.second;
            
            if(p==z)
            {
                
                //display(v);
                
                maxi = max(maxi,abs(v[0].second-v[v.size()-1].second));
                //cout<<"value of maxi is "<<maxi<<endl;
                
                
                
                v.clear();
                if(!q.empty())
                {
                    q.push(make_pair(z,-112));
                }
                
                
                
            }else{
                
                v.push_back(make_pair(p->val,hd));
                
                if(p->left!=NULL)
                {
                    //(ll) 2 * curr_idx + 1
                    q.push(make_pair(p->left,(long long)2*hd+1));
                }
                
                if(p->right!=NULL)
                {
                    q.push(make_pair(p->right,(long long)2*hd+2));
                }
                
            }
            
            
            
        }
        
        return maxi+1;
        
    }
};