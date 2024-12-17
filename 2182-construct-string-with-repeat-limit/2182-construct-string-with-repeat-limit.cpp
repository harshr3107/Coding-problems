class Solution {
public:
    string repeatLimitedString(string s, int rl) {
        
       map<char,int> mp;
        
        for(int i=0;i<s.length();i++)
        {
            mp[s.at(i)]++;
            
        }
        
        
        
        stack<pair<char,int>> st1;
        stack<pair<char,int>> st2;
        
        
        
       for(auto it: mp)
       {
           //cout<<it.first<<" "<<it.second<<endl;
           //st1.insert(it);
           st1.push(make_pair(it.first,it.second));
       }
        
        
        string ans="";
        
        while(!st1.empty())
        {
            //cout<<"current value of ans is "<<ans<<endl;
            
            pair<char,int> temp = st1.top();
            char c = temp.first;
            int freq = temp.second;
            
            //cout<<c<<" "<<freq<<endl;
            
            st1.pop();
            
            
            if(freq<=rl)
            {
                for(int i=0;i<freq;i++)
                {
                    ans+=c;
                }
                
            }else{
                
                
                for(int i=0;i<rl;i++)
                {
                    ans+=c;
                }
                
                if(st1.empty())
                {
                    return ans;
                }else{
                    
                    pair<char,int> temp2 = st1.top();
                    ans+=temp2.first;
                    st1.pop();
                    
                    if((temp2.second-1)!=0)
                    {
                        st1.push(make_pair(temp2.first,temp2.second-1));
                        
                    }
                    
                    st1.push(make_pair(c,freq-rl));
                    
                }
                
                
            }
            
        }
        
      
        
        
        
        return ans;
        
    }
};