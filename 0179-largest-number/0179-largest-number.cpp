class Solution {
public:
    
    /*bool static comp(string& a ,string& b)
    {
        int i=0;
        //int j=0;
        
        while(i<a.length() && i<b.length() && a.at(i)==b.at(i))
        {
            i++;
        }
        
        if(i<a.length() && i<b.length())
        {
        return a.at(i)>b.at(i);
        }
        
        if(i<a.length())
        {
            return  a.at(i)<' ';
        }else if(i<b.length())
        {
            return b.at(i)<' ';
        }
        
        return a>b;
    }*/
    
    
    static bool comp(string& a, string& b) {
        return a + b > b + a;  // Compare concatenated strings
    }
    
    
    string largestNumber(vector<int>& nums) {
        
        vector<string> v;
        string ans="";
        
        for(int i=0;i<nums.size();i++)
        {
            v.push_back(to_string(nums[i]));
        }
        
        sort(v.begin(),v.end(),comp);
        
        /*int i=0;
        for(i=0;i<v.size()-1;i++)
        {
            cout<<v[i]<<" ";
            
            //cout<<a<<" "<<b<<endl;
            
            if((stoll(v[i]+v[i+1]))>(stoll(v[i+1]+v[i])))
            {
                //cout<<"yaha pe aay\n";
                ans+=v[i];
            }else{
                
                //cout<<"yaha pe aaya bpssss\n";
                
                swap(v[i],v[i+1]);
                ans+=v[i];
                
            }
            
        }
        
        ans+=v[i];
        
        */
        
        for(int i=0;i<v.size();i++)
        {
            ans+=v[i];
        }
        
        
        while(ans.length()>1 && ans.at(0)=='0')
        {
            ans.erase(0,1);
            
        }
        
        cout<<ans<<endl;
        
        
        
        //cout<<endl;
        
        return ans;
        
    }
};