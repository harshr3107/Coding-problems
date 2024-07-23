class Solution {
public:
    
    static bool comp(pair<int,int> a,pair<int,int> b)
    {
        return a.second<b.second;
    }
    
    
    void sortmap(map<int,int>& m,vector<int>& ans)
    {
        vector<pair<int,int>> v;
        
        map<int,int>:: iterator it = m.begin();
        
        for(it=m.begin();it!=m.end();it++)
        {
            v.push_back(*it);
        }
        
        sort(v.begin(),v.end(),comp);
        
        
       
        
        
        
        int i=0;
        int j=0;
        vector<int> temp;
        
        while(i<v.size())
        {
            //cout<<"i entered here for "<<v[i].first<<endl;
            j=i;
            temp.push_back(v[i].first);
            while(j<v.size()-1 && v[j].second==v[j+1].second)
            {
                //cout<<"i entered here also \n";
                temp.push_back(v[j+1].first);
                j++;
            }
            
            if(temp.size()==1)
            {
                
                //cout<<"i entered in first loop for "<<temp[0]<<endl;
                
                int size = m[temp[0]];
                
                for(int i=0;i<size;i++)
                {
                    ans.push_back(temp[0]);
                }
                
                
            }else{
                
                //cout<<"i entered in second loop\n";
                
                //cout<<"size fo the answer here is "<<ans.size()<<endl;
                
                sort(temp.begin(),temp.end(),greater<int>());
                
                //cout<<"size of the temp is "<<temp.size()<<endl;
                cout<<m[temp[0]]<<endl;
                
                int size = m[temp[0]];
                
                for(int i=0;i<temp.size();i++)
                {
                    int j=0;
                    while(j<size)
                    {
                        ans.push_back(temp[i]);
                        j++;
                    }
                    
                }
                
                
                
            }
            
            temp.clear();
            i=j+1;
            
            
        }
        
        
        
            
          //we have sorted according to frequency now we need to solve trick case of same freq decreasing order
        
          
        
    
        
        
        
    }
    
    
    
    vector<int> frequencySort(vector<int>& nums) {
        
        map<int,int> m;
        vector<int> ans;
        
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        
        sortmap(m,ans);
        
       
        
        return ans;
        
    }
};