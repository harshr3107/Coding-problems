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
    
    int getallsubtreesum(TreeNode* root,map<int,int>& mp)
    {
        if(root==NULL)
        {
            return 0;
        }
        
        if(root->left==NULL && root->right==NULL)
        {
            mp[root->val]++;
            return root->val;
        }
        
        int left = getallsubtreesum(root->left,mp);
        int right = getallsubtreesum(root->right,mp);
        
       // mp[left+root->val]++;
        //mp[right+root->val]++;
        mp[left+right+root->val]++;
        
        
        return left+right+root->val;
        
        
        
        
    }
    
    
    static bool comp(pair<int,int> a,pair<int,int> b)
    {
        return a.first>b.first;
    }
    
    
    
    void sortmap(map<int,int> mp,vector<int>& v)
    {
        
        
        vector<pair<int,int>> vp;
        
        for(auto it: mp)
        {
            vp.push_back(make_pair(it.second,it.first));
        }
            
        
        
       sort(vp.begin(),vp.end(),comp);
        
        v.push_back(vp[0].second);
        int a = vp[0].first;
        
        
        for(int i=1;i<vp.size();i++)
        {
            if(vp[i].first==a)
            {
                v.push_back(vp[i].second);
            }else{
                break;
            }
        }
        
        
        
        
        
        
        
    }
    
    
    
        
    
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        
        map<int,int> mp;
        getallsubtreesum(root,mp);
        
        
        /*for(auto it: mp)
        {
            cout<<it.first<<" "<<it.second<<endl;
         }*/
        
        
        //cout<<endl;
        
        vector<int> v;
        
        sortmap(mp,v);
        
        
        
        
       
        
        return v;
        
        
    }
};