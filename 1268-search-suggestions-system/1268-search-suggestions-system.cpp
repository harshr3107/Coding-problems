class Solution {
public:
    
    class trienode{
        
        public:
        char data;
        trienode* children[26];
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
            
            int index=word[0]-'a';
            
            trienode* child;
            
            if(root->children[index]!=NULL)
            {
                child = root->children[index];
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
        
        
        
        void getallw(string& ans,trienode* root,vector<string>& v)
        {
            if(root==NULL)
            {
                return;
            }
            
            if(root->isterminal==true)
            {
                v.push_back(ans);
                if(v.size()==3)
                {
                    return;
                }
            }
            
            
            for(int i=0;i<26;i++)
            {
                if(root->children[i]!=NULL)
                {
                    ans.push_back(root->children[i]->data);
                    getallw(ans,root->children[i],v);
                    ans.pop_back();
                }
                
            }
            
            
            
            
        }
        
        
        
        
        void getsuggestutil(string word,trienode* root,vector<string>& v)
        {
            
            if(word.length()==0)
            {
                string ans=word;
                //cout<<"the current ans is "<<ans<<endl;
                getallw(ans,root,v);
                return;
            }
            
            
            int index = word[0]-'a';
            trienode* child;
            
            if(root->children[index]!=NULL)
            {
                child=root->children[index];
            }else{
                return;
            }
            
            getsuggestutil(word.substr(1),child,v);
            
            
        }
        
        
        
        void getsuggest(string word,vector<string>& v)
        {
            
            getsuggestutil(word,root,v);
            sort(v.begin(),v.end());
            //cout<<"yhe size of the string vector is "<<v.size()<<endl;
            if(v.size()>3)
            {
              v.erase(v.begin()+3,v.end());
            }
            
            for(int i=0;i<v.size();i++)
            {
                v[i].insert(0,word);
            }
        }
        
        
    };
    
    
    
    
    
    
    
    
    
    
    
    
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord)    {
        
        
      trie* t = new trie();
        
        for(int i=0;i<products.size();i++)
        {
            t->insert(products[i]);
        }
        
        vector<vector<string>> ans;
        vector<string> v;
        
        for(int i=0;i<searchWord.length();i++)
        {
           
            t->getsuggest(searchWord.substr(0,i+1),v);
            ans.push_back(v);
            v.clear();
            
            
        } 
        
        
        
        return ans;
            
        
        
        
    }
};