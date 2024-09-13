class Solution {
public:
    
    
    class trienode{
        
        public: 
        
       char data;
        trienode* children[10];
        bool isterminal;
        
        
        trienode(int c)
        {
            data=c;
            for(int i=0;i<10;i++)
            {
                children[i]=NULL;
            }
            
            isterminal=false;
            
        }
        
    };
    
    
    
    class trie{
        
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
            
            int index = word[0]-'0';
            trienode* child;
            
            if(root->children[index]!=NULL)
            {
                child=root->children[index];
            }else{
                
                child = new trienode(word[0]);
                root->children[index]=child;
                
            }
            
            insertutil(word.substr(1),child);
            
        }
        
        
        
        void insert(string word)
        {
            insertutil(word,root);
        }
        
        
        void getorderutil(trienode* root,string s,vector<int>& ans)
        {
            
            
            
            if(root->isterminal)
            {
                ans.push_back(stoi(s));
                
            }
            
            
            
            for(int i=0;i<10;i++)
            {
                if(root->children[i]!=NULL)
                {
                    s.push_back(root->children[i]->data);
                    getorderutil(root->children[i],s,ans);
                    s.pop_back();
                    
                    
                }
                
            }
            
            
        }
        
        
        
        void getorder(vector<int>& ans)
        {
            string s="";
            getorderutil(root,s,ans);
            
        }
        
        
        
    };
    
    
    
    
    vector<int> lexicalOrder(int n) {
        
        trie* t = new trie();
        
        for(int i=1;i<=n;i++)
        {
            t->insert(to_string(i));
        }
        
        vector<int> ans;
        
        t->getorder(ans);
        
        
      
        
        return ans;
        
        
    }
};