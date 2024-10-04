class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
       
        sort(skill.begin(),skill.end());
        
        int i=0;
        int j = skill.size()-1;
        
        int h = skill[i]+skill[j];
        
        //cout<<"val of h is "<<h<<endl;
        
       
        long long ans=1;
        ans = skill[i]*skill[j];
        
        //cout<<"val of ans is "<<ans<<endl;
        
         i++;
        j--;
        
        
        while(j>i)
        {
            
            if(skill[i]+skill[j]!=h)
            {
                return -1;
            }
            
            ans+=(skill[i]*skill[j]);
            
            i++;
            j--;
            
        }
       
        
        return ans;
        
    }
};