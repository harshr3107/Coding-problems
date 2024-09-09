class Solution {
public:
    
    class trienode
    {
        public:
        
        char data;
        trienode* children[26];
        int childcount=0;
        bool isterminal;
        
        trienode(char a)
        {
            data=a;
            for(int i=0;i<26;i++)
            {
                children[i]=NULL;
            }
            
            isterminal=false;
        }
        
    
        
        
    };
    
    
    class trie
    {
        public:
        
        trienode* root;
        
        
        trie()
        {
            root = new trienode('-');
            
        }
        
        
        void insertutil(string word,trienode* root)
        {
            
            if(word.length()==0)
            {
                root->isterminal=true;
                return;
            }
            
            int index = word[0]-'a';
            
            trienode* child;
            
            if(root->children[index]!=NULL)
            {
                child = root->children[index];
                
            }else{
                
                child = new trienode(word[0]);
                root->children[index]=child;
                root->childcount++;
                
            }
            
            insertutil(word.substr(1),child);
            
            
        }
        
        
        trienode* getchild(trienode* root)
        {
            for(int i=0;i<26;i++)
            {
                if(root->children[i]!=NULL)
                {
                    return root->children[i];
                }
            }
            
            return NULL;
        }
        
        
        
        
        
        string getans(string& ans,trienode* root)
        {
            trienode* child;
            int a = root->childcount;
            
            if(root->isterminal==true)
            {
                return ans;
            }
            
            if(a==1)
            {
                
                 child = getchild(root);
                 cout<<"i am here entered "<<child->data<<endl; 
                 ans+=child->data;
                 getans(ans,child);
            }
            
                
                return ans;
            
            
            
            
        }
        
        
        
        
        
        void insert(string word)
        {
            insertutil(word,root);
        }
        
        
        string check()
        {
            string ans="";
            
            return getans(ans,root);
            
        }
        
        
        
        
        
        
        
        
    };
    
    
    string longestCommonPrefix(vector<string>& strs) {
        
      trie* t = new trie();
        
        for(int i=0;i<strs.size();i++)
        {
            if(strs[i]=="")
            {
                return "";
            }
            t->insert(strs[i]);
        }
        
       
        
        return t->check();
        
        
    }
};