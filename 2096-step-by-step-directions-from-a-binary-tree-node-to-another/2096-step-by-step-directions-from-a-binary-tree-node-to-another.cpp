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
    
    
    bool getpath(TreeNode* root,int s,vector<pair<int,char>>& v)
    {
        
        if(root==NULL)
        {
            return false;
        }
        
        if(root->val==s)
        {
            
            return true;
        }
        
        v.push_back(make_pair(root->val,'L'));
        if(getpath(root->left,s,v)==true)
        {
            return true;
        }
        v.pop_back();
        v.push_back(make_pair(root->val,'R'));
        if(getpath(root->right,s,v)==true)
        {
            return true;
        }
        v.pop_back();
        
        
        return false;
        
    }
    
    
    void display(vector<pair<int,char>> v)
    {
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i].first<<v[i].second<<"  ";
        }
        
        cout<<endl;
    }
    
    
    
    
    string getDirections(TreeNode* root, int s, int d) {
        
        vector<pair<int,char>> v1;
        vector<pair<int,char>> v2;
        
        getpath(root,s,v1);
        getpath(root,d,v2);
        
       // display(v1);
        //display(v2);
        
        int i=0;
        int j=0;
        
        while(i<v1.size() && j<v2.size())
        {
            
            if(v1[i]==v2[j])
            {
                i++;
                j++;
                continue;
            }
            
            
            if((i+1)<v1.size() && (j+1)<v2.size() && v1[i+1].first==v2[j+1].first)
            {
                i++;
                j++;
            }else{
                break;
            }
            
            
        }
        
        //cout<<"val of i is "<<i<<" and j is "<<j<<endl;
        
        string ans="";
        
       for(int k=i;k<v1.size();k++)
       {
           ans+='U';
       }
    
       for(int k=j;k<v2.size();k++)
       {
           ans+=v2[k].second;
       }
        
        
        
        return ans;
        
    }
};