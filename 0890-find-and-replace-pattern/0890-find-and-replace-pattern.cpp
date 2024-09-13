class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        
      
        
        vector<string> ans;
        
        for(int i=0;i<words.size();i++)
        {
            int a=0;
            vector<bool> visited(26,false);
            map<char,char> mp;
            
            for(int j=0;j<words[i].length();j++)
            {
                
                if(mp.count(pattern[j]))
                {
                    if(mp[pattern[j]]!=words[i].at(j))
                    {
                        a++;
                        break;
                    }
                }else{
                    
                    if(visited[words[i].at(j)-'a'])
                    {
                        a++;
                        break;
                    }
                    
                    mp[pattern[j]]=words[i].at(j);
                    visited[words[i].at(j)-'a']=true;
                    
                }
                
                if(a>0)
                {
                    break;
                }
                
                
            }
            
            if(a==0)
            {
                //cout<<"i am here for the word "<<words[i]<<endl;
                 ans.push_back(words[i]);
            }
            
            
            
            
        }
        
        
        return ans;
        
    }
};