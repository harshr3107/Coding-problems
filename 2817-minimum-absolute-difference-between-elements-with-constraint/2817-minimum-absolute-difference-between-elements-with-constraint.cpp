class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        
       
        
        
        int i=0;
        int j=x;
        set<int> s;
        int mini=INT_MAX;
        set<int> :: iterator it;
        
        for(int i=x;i<nums.size();i++)
        {
            s.insert(nums[i-x]);
            
            //cout<<"i am "<<nums[i]<<endl;
            
            it=s.lower_bound(nums[i]);
            
            if(it==s.end())
            {
                //cout<<"mai toh yehi hoon\n";
                if(it!=s.begin())
                {
                    it--;
                }
                
                mini = min(mini,abs((*it)-nums[i]));
                
                
                
            }else{
                
                //cout<<"maiii yaha aagaya nnnn\n";
                
                mini = min(mini,abs((*it)-nums[i]));
                //cout<<"value of mini is "<<mini<<endl;
                set<int> :: iterator it2=it;
                it2++;
                
                if(it!=s.begin())
                {
                    //cout<<"kya bolrah public\n";
                    --it;
                    
                    mini = min(mini,abs((*it)-nums[i]));
                }
                
                if(it2!=s.end())
                {
                    //cout<<"aur bolo bhaiyo";
                     mini = min(mini,abs((*it2)-nums[i]));
                }
                
                
                
            }
            
            
           
        }
        
        
        return mini;
        
        
        
        
    }
};