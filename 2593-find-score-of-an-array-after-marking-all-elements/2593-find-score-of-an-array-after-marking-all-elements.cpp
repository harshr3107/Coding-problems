class Solution {
public:
    
    static bool comp(pair<int,int>& a,pair<int,int>& b)
    {
        if(a.first==b.first)
        {
            return a.second<b.second;
        }
        
        return a.first<b.first;
        
    }
    
    
    long long findScore(vector<int>& nums) {
        
        vector<pair<int,int>> v;
        
        for(int i=0;i<nums.size();i++)
        {
            v.push_back(make_pair(nums[i],i));
        }
        
        sort(v.begin(),v.end(),comp);
            
            
        
        long long score=0;
        vector<bool> visited(nums.size(),false);
        
        int i=0;
        
        while(i<nums.size())
        {
            
            int ind = v[i].second;
            int a=0;
            while(visited[ind]!=false)
            {
                i++;
                if(i==nums.size())
                {
                    a++;
                    break;
                }
                
                ind = v[i].second;
                
            }
            
            if(a!=0)
            {
                break;
            }
            
            score+=v[i].first;
           // cout<<"i took "<<v[i].first<<" from index "<<v[i].second<<endl;
            //cout<<"current score is "<<score<<endl<<endl;
            visited[ind]=true;
            if((ind-1)>=0)
            {
                visited[ind-1]=true;
            }
            if((ind+1)<nums.size())
            {
                visited[ind+1]=true;
            }
            i++;
                
        }    
            
        
        return score;
        
        
        
      
        
    }
};