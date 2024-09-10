class Solution {
public:
    
    
    
    class trienode
    {
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
            root->isterminal=true;
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
                
            }
            
            insertutil(word.substr(1),child);
            
        }
        
        
        
        
        
        void insert(string word)
        {
            insertutil(word,root);
        }
        
        
        bool isallterminal(string word,trienode* root)
        {
            //cout<<"i entered here for the word "<<word<<endl;
            
            if(word.length()==0)
            {
               return true;
            }
            
            int index = word[0]-'a';
            
                if(root->isterminal!=true)
                {
                    return false;
                }
            
            trienode* child;
            
            if(root->children[index]!=NULL)
            {
                child = root->children[index];
                
            }
            
            if(isallterminal(word.substr(1),child)==false)
            {
                return false;
            }
            
            return true;
            
            
           
            
        }
        
        
        
        string getlongest(vector<string> words)
        {
            vector<string> v;
            //priorit_queue<pair<int,string>> maxheap;
            
            //cout<<"i entered here\n";
            
            for(int i=0;i<words.size();i++)
            {
                if(isallterminal(words[i],root)==true)
                {
                    //cout<<"i entered here for--- "<<words[i]<<endl;
                    v.push_back(words[i]);
                }
            }
            
           
            
            sort(v.begin(),v.end());
            //cout<<"\n\n size od the vector is "<<v.size()<<endl;
            
            if(v.size()==0)
            {
                return "";
            }
            
            string ans=v[0];
            
            for(int i=1;i<v.size();i++)
            {
                if(ans.length()<v[i].length())
                {
                    ans=v[i];
                }
            }
            
            
            return ans;
            
            //return "harsh";
        }
        
        
        
    };
    
    
    
    
    
    
    string longestWord(vector<string>& words) {
        
        trie* t = new trie();
        
        for(int i=0;i<words.size();i++)
        {
            t->insert(words[i]);
        }
        
        string h = t->getlongest(words);
        
        return h;
        
        
        
    }
};