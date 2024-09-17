class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        
        unordered_map<string,int> m1;
        
        
        
       
       
        
        
        while(s1.find(" ")!=string::npos)
        {
            string s = s1.substr(0,s1.find(" "));
            s1.erase(0,s1.find(" ")+1);
            m1[s]++;
        }
        
        //cout<<"mai bahar aagaya\n";
        
        if(s1!="")
        {
            m1[s1]++;
        }
        
        unordered_map<string,int> m2;
        
        while(s2.find(" ")!=string::npos)
        {
            string s = s2.substr(0,s2.find(" "));
            s2.erase(0,s2.find(" ")+1);
            m2[s]++;
        }
        
        if(s2!="")
        {
            m2[s2]++;
        }
        
        
        vector<string> ans;
        
        
      for(auto it : m1)
       {
           if(!m2.count(it.first) && it.second==1)
           {
               ans.push_back(it.first);
               
           }else{
            
                m2.erase(it.first);
           }
           
           
           
       }
        
        for(auto it : m2)
        {
            if(it.second==1)
            {
           ans.push_back(it.first);
            }
        }
        
      
        
        
        
        
         
        return ans;
        
    }
};