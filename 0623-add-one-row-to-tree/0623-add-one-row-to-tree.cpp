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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        
        queue<pair<TreeNode*,int>> q;
        
        q.push(make_pair(root,1));
        
        if(depth==1)
        {
            TreeNode* n = new TreeNode(val);
            n->left=root;
            root=n;
            return root;
        }
        
       
        
        
        while(!q.empty())
        {
            pair<TreeNode*,int>  tempo = q.front();
            q.pop();
            TreeNode* temp = tempo.first;
            int level = tempo.second;
            
           if(temp!=NULL)
           {
               if(level==depth-1)
               {
                  // cout<<"i entered here for "<<temp->val<<endl;
                   
                  // cout<<temp->left->val<<" "<<temp->right->val<<endl;
                   
                   TreeNode* leftt = temp->left;
                   TreeNode* rightt = temp->right;
                   
                   
                   
                   
                   
                       TreeNode* n = new TreeNode(val);
                       temp->left=n;
                       n->left=leftt;
                   
                  
                   
                      
                   
                   
                       TreeNode* k = new TreeNode(val);
                       temp->right=k;
                       k->right=rightt;
                   
                  
                   
                   
               }else{
                   
                   if(temp->left!=NULL)
                   {
                       q.push(make_pair(temp->left,level+1));
                   }
                   
                   if(temp->right!=NULL)
                   {
                       q.push(make_pair(temp->right,level+1));
                   }
                   
                   
                   
                   
               }
               
               
           }
            
            
            
        }
        
        
        
        
        return root;
        
        
    }
};