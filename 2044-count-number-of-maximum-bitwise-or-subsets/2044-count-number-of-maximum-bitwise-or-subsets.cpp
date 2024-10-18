class Solution {
public:
    
    
    void getans(vector<int> nums,vector<int>& v,int& h,int cindex,int maxor)
    {
       // cout<<"i am at cindex = "<<cindex<<endl;
        
        if(cindex==nums.size())
        {
           // cout<<"i entered here for "<<cindex<<endl;
            
            int k=0;
            for(int i=0;i<v.size();i++)
            {
               // cout<<v[i]<<" ";
                k=(k|v[i]);
            }
            
        
            
            if(k==maxor)
            {
                h++;
            }
            
            return;
            
        }
        
        
        v.push_back(nums[cindex]);
        getans(nums,v,h,cindex+1,maxor);
        v.pop_back();
        getans(nums,v,h,cindex+1,maxor);
        
    }
    
    
    
    
    
    
    int countMaxOrSubsets(vector<int>& nums) {
        
        int maxor=0;
        
        for(int i=0;i<nums.size();i++)
        {
            maxor=(maxor|nums[i]);
        }
        
        //cout<<"the max or is "<<maxor<<endl;
        
        vector<int> v;
        int h=0;
        int cindex=0;
            
        getans(nums,v,h,cindex,maxor);
        
        return h;
        
        
        
        
        
        
        
    }
};