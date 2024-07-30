class Solution {
public:
    int firstUniqChar(string s) {
        
        vector<int> count(26);
        //queue<int> q;
        
        
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