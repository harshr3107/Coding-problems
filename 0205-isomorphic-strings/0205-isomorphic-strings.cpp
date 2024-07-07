class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        
        map<char,char> mp;
        vector<bool> v(128,false); 
        bool ans=true;
        
        
        for(int i=0;i<s.length();i++)
        {
            //cout<<"i entered here for "<<s.at(i)<<endl;
            //cout<<"element is present or not "<<mp.count(s.at(i))<<endl;
        
            
            if(mp.count(s.at(i)))
            {
                if(mp[s.at(i)]!=t.at(i))
                {
                 //cout<<"value for the element "<<mp[s.at(i)]<<" "<<t.at(i)<<endl;
                 //cout<<"i entered here for "<<s.at(i)<<endl;
                 ans=false;
                 break;
                }else{
                    continue;
                }
                
            }else{
                
                
                
                
                if(v[t.at(i)-'!'+1]==false)
                {
                    //cout<<"me itha pan aalo"<<endl;
                  mp[s.at(i)]=t.at(i);
                    cout<<mp[s.at(i)]<<endl;
                  v[t.at(i)-'!'+1]=true;
                }else{
                   // cout<<mp[s.at(i)]<<endl;
                    ans=false;
                    //cout<<"answer was given here\n";
                    return false;
                }
                
            }
           
        }
        
        
        //cout<<"value of ans is "<<ans<<endl;
        return ans;
        
       
        
        
        
       
    }
};