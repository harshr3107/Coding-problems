/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        if(root==NULL)
        {
            return root;
        }
        
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        
        vector<Node*> v;
        
        
        while(!q.empty())
        {
            
            Node* temp=q.front();
            q.pop();
            
            
            if(temp==NULL)
            {
                
                if(v.size()==1)
                {
                    v[0]->next=NULL;
                }else{
                    
                    int i=0;
                    for(i=0;i<v.size()-1;i++)
                    {
                        v[i]->next=v[i+1];
                    }
                    
                    v[i]->next=NULL;
                    
                }
                
                v.clear();
                
                if(!q.empty())
                {
                    q.push(NULL);
                }
                
               
                
            }else{
               
                v.push_back(temp);
                
                if(temp->left!=NULL)
                {
                    q.push(temp->left);
                }
                if(temp->right!=NULL)
                {
                    q.push(temp->right);
                }
                
                
            }
            
            
            
            
            
        }
            
        
        
        
        
        return root;
    }
};