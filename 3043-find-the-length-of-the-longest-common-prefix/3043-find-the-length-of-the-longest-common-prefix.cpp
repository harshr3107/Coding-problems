class Solution {
public:
    
    class trienode{
       
        public:
        
        char data;
        trienode* children[10];
        bool isterminal;
        
        
        trienode(char a)
        {
            data=a;
            for(int i=0;i<10;i++)
            {
                children[i]=NULL;
            }
            
            isterminal=false;  
            
        }
        
       
    };
    
    
    
    
    void insert(trienode* root,string word)
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
            child = root->children[index];
        }else{
            
            child = new trienode(word[0]);
            root->children[index]=child;
        }
        
        insert(child,word.substr(1));
    }
    
    
    bool getprefixlen(trienode* root,string word,int& h)
    {
        
        if(word.length()==0)
        {
            return true;
        }
        
        int index = word[0]-'0';
        
        if(root->children[index]==NULL)
        {
            return false;
        }else{
            h=h+1;
        }
        
        if(getprefixlen(root->children[index],word.substr(1),h)==false)
        {
            return false;
        }
        
        return true;
        
        
    }
    
    
    
    
    
    
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        
        trienode* root = new trienode('-');
        
        
        for(int i=0;i<arr1.size();i++)
        {
            insert(root,to_string(arr1[i]));
        }
        
        int ans=0;
        
        for(int i=0;i<arr2.size();i++)
        {
            string word = to_string(arr2[i]);
            int h=0;
            if(word.length()>ans)
            {
                getprefixlen(root,word,h);
                //cout<<"The prefix val of "<<word<<" is "<<h<<endl;
                ans=max(ans,h);
            }
            
        }
        
        
        return ans;
        
    }
};