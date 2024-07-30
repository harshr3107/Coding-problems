class Solution {
public:
    int firstUniqChar(string s) {
        
        vector<int> count(26);
        queue<int> q;
        
        
        
        int i=0;
       
        
        while(i<s.length())
        {
            //cout<<"value of q front is "<<q.front()<<endl;
            
            while(!q.empty() && count[s.at(q.front())-'a']>1)
            {
                //cout<<"i entered here for "<<i<<endl;
                q.pop();
            }
           
            
            //cout<<"frequency of i is "<<count[s.at(i)-'a']<<endl;
            if(count[s.at(i)-'a']==0)
            {
               q.push(i);
            }
            count[s.at(i)-'a']++;
            i++;
            
        }
        
        
        if(!q.empty() && count[s.at(q.front())-'a']>1)
        {
            q.pop();
        }
        
        if(q.empty())
        {
            return -1;
        }
        
        return q.front();
        
        
        
        
        
        
        
        
        
        
        
        
        
       //bRUTE FORCE APPROACH
        /*
        int i=0;
        
        
        for(int i=0;i<s.length();i++)
        {
            count[s.at(i)-'a']++;
        }
        
        for(int i=0;i<s.length();i++)
        {
            if(count[s.at(i)-'a']==1)
            {
                return i;
            }
        }
        
        
        return -1;
        
        
       /* while(i<=s.length())
        {
            if(q.empty())
            {
                q.push(i);
                count(s.at(i)-'a')++;
            }else{
                
                
                
                
            }
            
        }
        */
        
       
        
        
        
    }
};