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
    
    

    
    
    
    
    pair<int,int> getans(TreeNode* root,vector<int>& v)
    {
        
        
        
        if(root==NULL)
        {
            return make_pair(0,0);
        }
        
        
        if(root->left==NULL && root->right==NULL)
        {
          
            v.push_back(1);
             return make_pair(1,1);
        }
        
        
        pair<int,int> l = getans(root->left,v);
        pair<int,int> r = getans(root->right,v);
        
        //cout<<"i am at "<<root->val<<" the l is "<<l.first<<" "<<l.second<<" the val of r is "<<r.first<<" "<<r.second<<endl;
        
        
        if(l.first==r.first && (l.second+r.second+1)==pow(2,l.first+1)-1)
        {
            v.push_back(l.second+r.second+1);
        }
        
        
        
        
        
        
        
        return make_pair(1+max(l.first,r.first),l.second+r.second+1);
        
        
        
        
        
        
        
    }
    
    
    
    
    
    
    
    
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        
     priority_queue<int,vector<int>,greater<int>> mh;
        
       
        vector<int> v;
        
        getans(root,v);
        
        /*for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }*/
        
        
        sort(v.begin(),v.end(),greater<int>());
        
        if(v.size()<k)
        {
            return -1;
        }
        
        cout<<endl;
        
        return v[k-1];
        
        
        
        
        
        
        
        
    }
};