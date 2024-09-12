class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        vector<string> s1;
        vector<char> s2;
        
        vector<bool> visited(26,false);
        map<string,char> mp;
        
        for(int i=0;i<pattern.size();i++)
        {
            s2.push_back(pattern[i]);
        }
        
        while(s.find(" ")!=string::npos)
        {
            //cout<<"mai yaha hoon\n";
            int a = s.find(" ");
            s1.push_back(s.substr(0,a));
            s.erase(0,a+1);
            
        }
        
        s1.push_back(s);
        
        if(s1.size()!=s2.size())
        {
            return false;
        }
        
        
        for(int i=0;i<s1.size();i++)
        {
            //cout<<s1[i]<<" "<<s2[i]<<endl;
            if(mp.count(s1[i]))
            {
                if(mp[s1[i]]!=s2[i])
                {
                    return false;
                }
            }else{
                
                if(visited[s2[i]-'a'])
                {
                    return false;
                }
                
                mp[s1[i]]=s2[i];
                
                visited[s2[i]-'a']=true;
                
            }
        }
        
        return true;
        
        
    }
};