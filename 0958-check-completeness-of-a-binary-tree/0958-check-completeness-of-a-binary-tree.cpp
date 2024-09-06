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
    
    
    void display(vector<int> v)
    {
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
        
        cout<<endl;
    }
    
    
    bool isCompleteTree(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);
        vector<int> v;
        
        while(!q.empty())
        {
            
            TreeNode* temp = q.front();
            q.pop();
            
            v.push_back(temp->val);
            
            if(temp->val!=-1)
            {
            
            if(temp->left!=NULL)
            {
                q.push(temp->left);
            }else{
                q.push(new TreeNode(-1));
            }
            
            if(temp->right!=NULL)
            {
                q.push(temp->right);
            }else{
                  q.push(new TreeNode(-1));
            }
                
            }
            
        }
        
        
       // display(v);
        
        vector<int>:: iterator it;
        it = find(v.begin(),v.end(),-1);
        
        int index = it-v.begin();
        
        for(int j=index+1;j<v.size();j++)
        {
            if(v[j]!=-1)
            {
                return false;
            }
        }
        
        //cout<<"the first element where i get -1 is "<<index<<endl;
        
        
        //vector<int>
        
        
        return true;
            
            
            
        
    }
};